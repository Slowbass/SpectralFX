// SpectralFX — partie « spectre brisé » (C++, sans JUCE).
//
// Le son est découpé en tranches qui se chevauchent (transformée de Fourier, « FFT »).
// Pour chaque tranche on connaît l'intensité et la fréquence exacte de chaque composante
// (méthode du « vocodeur de phase »). On peut alors :
//   - prolonger les composantes (Traîne),
//   - figer le spectre (Geler),
//   - ne garder que les composantes les plus fortes (Épure),
//   - éparpiller les composantes au hasard (Brisure),
//   - multiplier les fréquences (Étirement) ou leur ajouter un écart fixe (Décalage),
// puis on reconstruit le son.
#pragma once

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdint>
#include <vector>

namespace sfx
{

constexpr double twoPi = 6.283185307179586476925286766559;

// Taille des tranches selon la fréquence d'échantillonnage (même finesse en Hz partout)
inline int fftSizeFor (double sampleRate)
{
    if (sampleRate <= 50000.0) return 2048;
    if (sampleRate <= 100000.0) return 4096;
    return 8192;
}

// FFT complexe radix-2, en place
class FFT
{
public:
    void init (int size)
    {
        n = size;
        int bits = 0;
        while ((1 << bits) < n) ++bits;
        rev.assign ((size_t) n, 0);
        for (int i = 0; i < n; ++i)
        {
            int r = 0;
            for (int b = 0; b < bits; ++b) if (i & (1 << b)) r |= 1 << (bits - 1 - b);
            rev[(size_t) i] = r;
        }
        tw.resize ((size_t) n / 2);
        for (int i = 0; i < n / 2; ++i)
            tw[(size_t) i] = std::polar (1.0, -twoPi * i / n);
    }

    void transform (std::complex<double>* d, bool inverse) const
    {
        for (int i = 0; i < n; ++i)
            if (i < rev[(size_t) i]) std::swap (d[i], d[rev[(size_t) i]]);
        for (int len = 2; len <= n; len <<= 1)
        {
            const int halfLen = len / 2, step = n / len;
            for (int i = 0; i < n; i += len)
                for (int j = 0; j < halfLen; ++j)
                {
                    auto w = tw[(size_t) (j * step)];
                    if (inverse) w = std::conj (w);
                    const auto u = d[i + j];
                    const auto v = d[i + j + halfLen] * w;
                    d[i + j] = u + v;
                    d[i + j + halfLen] = u - v;
                }
        }
    }

private:
    int n = 0;
    std::vector<int> rev;
    std::vector<std::complex<double>> tw;
};

struct SpectreReglages
{
    bool geler = false;
    float traine = 0;       // 0..1
    float decalage = 0;     // Hz
    float etirement = 1;    // rapport
    float brisure = 0;      // 0..1
    float epure = 0;        // 0..1
};

class SpectreCanal
{
public:
    void prepare (double sampleRate, unsigned seed)
    {
        sr = sampleRate;
        n = fftSizeFor (sr);
        hop = n / 4;
        half = n / 2;
        binHz = sr / n;
        fft.init (n);
        win.resize ((size_t) n);
        for (int i = 0; i < n; ++i) win[(size_t) i] = 0.5 - 0.5 * std::cos (twoPi * i / n);
        auto z = [&] (std::vector<double>& v, size_t s) { v.assign (s, 0.0); };
        z (inRing, (size_t) n); z (outAcc, (size_t) n); z (outQ, (size_t) hop);
        const size_t b = (size_t) half + 1;
        z (lastPh, b); z (lisse, b); z (freqMem, b); z (gelMag, b); z (gelFreq, b);
        z (synPh, b); z (outMag, b); z (outFreq, b); z (best, b); z (srcMag, b); z (srcFreq, b); z (anMag, b);
        z (brisR, b);
        cplx.assign ((size_t) n, {});
        rng = seed * 2654435761u + 12345u;
        for (auto& r : brisR) r = rand11();
        for (size_t k = 0; k < b; ++k) freqMem[k] = gelFreq[k] = (double) k * binHz;
        ringPos = hopCount = qPos = 0;
        gel = 0; etaitGele = false;
    }

    int latency() const { return n; }

    float tick (float x, const SpectreReglages& s)
    {
        inRing[(size_t) ringPos] = std::isfinite (x) ? x : 0.0f;
        if (++ringPos == n) ringPos = 0;
        const double y = outQ[(size_t) qPos++];
        if (++hopCount == hop)
        {
            hopCount = 0;
            qPos = 0;
            frame (s);
        }
        return (float) y;
    }

private:
    double rand11()
    {
        rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5;
        return (double) (rng & 0xffffff) / (double) 0x800000 - 1.0;
    }

    static double wrap (double p)
    {
        return p - twoPi * std::floor ((p + twoPi * 0.5) / twoPi);
    }

    void frame (const SpectreReglages& s)
    {
        for (int j = 0; j < n; ++j)
            cplx[(size_t) j] = { inRing[(size_t) ((ringPos + j) % n)] * win[(size_t) j], 0.0 };
        fft.transform (cplx.data(), false);

        // fondu du gel (0,15 s)
        if (s.geler && ! etaitGele)
        {
            gelMag = lisse;
            gelFreq = freqMem;
        }
        etaitGele = s.geler;
        const double pas = hop / (sr * 0.15);
        gel = s.geler ? std::min (1.0, gel + pas) : std::max (0.0, gel - pas);

        const bool neutre = gel <= 0.0 && s.traine < 1e-4f && std::abs (s.decalage) < 0.01f
                         && std::abs (s.etirement - 1.0f) < 1e-4f && s.brisure < 1e-4f && s.epure < 1e-4f;

        // analyse : intensité et fréquence exacte de chaque composante
        const double attendu = twoPi * hop / n;
        const double T = 12.0 * s.traine * s.traine;
        const double d = T > 1e-4 ? std::exp (-hop / (sr * T)) : 0.0;
        for (int k = 0; k <= half; ++k)
        {
            const auto c = cplx[(size_t) k];
            const double mag = std::abs (c);
            const double ph = std::arg (c);
            const double dev = wrap (ph - lastPh[(size_t) k] - attendu * k);
            lastPh[(size_t) k] = ph;
            const double f = (k + dev / attendu) * binHz;
            anMag[(size_t) k] = mag;

            double& l = lisse[(size_t) k];
            l = mag > l ? mag : l * d + mag * (1.0 - d);
            if (mag >= 0.5 * l) freqMem[(size_t) k] = f;
            if (neutre) synPh[(size_t) k] = ph;
        }

        if (! neutre)
        {
            // source : spectre prolongé, mélangé au spectre gelé
            for (int k = 0; k <= half; ++k)
            {
                srcMag[(size_t) k] = lisse[(size_t) k] * (1.0 - gel) + gelMag[(size_t) k] * gel;
                srcFreq[(size_t) k] = gel > 0.5 ? gelFreq[(size_t) k] : freqMem[(size_t) k];
            }

            // épure : on ne garde que les pics les plus forts
            if (s.epure > 1e-4f)
            {
                double mx = 0;
                for (int k = 1; k < half; ++k) mx = std::max (mx, srcMag[(size_t) k]);
                const double seuil = mx * std::pow (10.0, (-100.0 + 75.0 * s.epure) / 20.0);
                const double att = 1.0 - s.epure;
                double prev = srcMag[0];
                for (int k = 1; k < half; ++k)
                {
                    const double m = srcMag[(size_t) k];
                    const bool pic = m >= prev && m >= srcMag[(size_t) k + 1] && m > seuil;
                    prev = m;
                    if (! pic) srcMag[(size_t) k] = m * att;
                }
            }

            // brisure : quelques composantes changent de place à chaque tranche
            const double brisHz = s.brisure * s.brisure * 1200.0;
            const double renouv = 0.004 + 0.03 * s.brisure;
            for (int k = 1; k < half; ++k)
                if ((rand11() * 0.5 + 0.5) < renouv) brisR[(size_t) k] = rand11();

            // nouvelle place de chaque composante
            std::fill (outMag.begin(), outMag.end(), 0.0);
            std::fill (best.begin(), best.end(), 0.0);
            const double nyq = sr * 0.49;
            for (int k = 1; k < half; ++k)
            {
                const double m = srcMag[(size_t) k];
                if (m < 1e-9) continue;
                const double f = srcFreq[(size_t) k] * s.etirement + s.decalage + brisR[(size_t) k] * brisHz;
                if (f < 15.0 || f > nyq) continue;
                const int k2 = (int) std::lround (f / binHz);
                if (k2 < 1 || k2 >= half) continue;
                outMag[(size_t) k2] += m;
                if (m > best[(size_t) k2]) { best[(size_t) k2] = m; outFreq[(size_t) k2] = f; }
            }

            // synthèse : la phase de chaque composante avance selon sa fréquence
            cplx[0] = {};
            cplx[(size_t) half] = {};
            for (int k = 1; k < half; ++k)
            {
                const double m = outMag[(size_t) k];
                if (m > 0.0)
                {
                    synPh[(size_t) k] = wrap (synPh[(size_t) k] + twoPi * hop * outFreq[(size_t) k] / sr);
                    cplx[(size_t) k] = std::polar (m, synPh[(size_t) k]);
                }
                else
                {
                    synPh[(size_t) k] = wrap (synPh[(size_t) k] + attendu * k);
                    cplx[(size_t) k] = {};
                }
                cplx[(size_t) (n - k)] = std::conj (cplx[(size_t) k]);
            }
        }

        fft.transform (cplx.data(), true);

        // addition des tranches (fenêtre de Hann deux fois, recouvrement 4 : somme = 1,5)
        const double norme = 1.0 / (n * 1.5);
        for (int j = 0; j < n; ++j)
            outAcc[(size_t) j] += cplx[(size_t) j].real() * win[(size_t) j] * norme;
        for (int j = 0; j < hop; ++j) outQ[(size_t) j] = outAcc[(size_t) j];
        std::move (outAcc.begin() + hop, outAcc.end(), outAcc.begin());
        std::fill (outAcc.end() - hop, outAcc.end(), 0.0);
    }

    double sr = 48000, binHz = 1;
    int n = 2048, hop = 512, half = 1024;
    FFT fft;
    std::vector<double> win, inRing, outAcc, outQ;
    std::vector<double> lastPh, lisse, freqMem, gelMag, gelFreq, synPh, outMag, outFreq, best, srcMag, srcFreq, anMag, brisR;
    std::vector<std::complex<double>> cplx;
    int ringPos = 0, hopCount = 0, qPos = 0;
    double gel = 0;
    bool etaitGele = false;
    uint32_t rng = 1;
};

} // namespace sfx
