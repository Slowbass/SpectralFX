// Outil d'essai hors JUCE : passe un fichier WAV (16 bits stéréo) dans le moteur SpectralFX.
// Usage : rendu entree.wav sortie.wav scenario.txt [frequence]
// scenario : lignes « temps_en_s id=valeur id=valeur ... » (les réglages changent à ce temps)
// Compilation : g++ -O2 -std=c++17 -I src -I generated outils/rendu.cpp -o rendu
#include "Moteur.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

static bool lireWav (const char* f, std::vector<float>& l, std::vector<float>& r, int& sr)
{
    std::ifstream in (f, std::ios::binary);
    if (! in) return false;
    char hdr[12]; in.read (hdr, 12);
    int ch = 2, bits = 16;
    while (in)
    {
        char id[4]; uint32_t sz = 0;
        in.read (id, 4); in.read ((char*) &sz, 4);
        if (! in) break;
        if (std::string (id, 4) == "fmt ")
        {
            std::vector<char> b (sz); in.read (b.data(), sz);
            ch = *(uint16_t*) &b[2]; sr = (int) *(uint32_t*) &b[4]; bits = *(uint16_t*) &b[14];
        }
        else if (std::string (id, 4) == "data")
        {
            std::vector<int16_t> d (sz / 2); in.read ((char*) d.data(), sz);
            const size_t n = d.size() / (size_t) ch;
            l.resize (n); r.resize (n);
            for (size_t i = 0; i < n; ++i) { l[i] = d[i * ch] / 32768.0f; r[i] = d[i * ch + (ch > 1)] / 32768.0f; }
            return bits == 16;
        }
        else in.seekg (sz, std::ios::cur);
    }
    return false;
}

static void ecrireWav (const char* f, const std::vector<float>& l, const std::vector<float>& r, int sr)
{
    std::ofstream o (f, std::ios::binary);
    const uint32_t n = (uint32_t) l.size(), data = n * 4;
    auto w32 = [&] (uint32_t v) { o.write ((char*) &v, 4); };
    auto w16 = [&] (uint16_t v) { o.write ((char*) &v, 2); };
    o.write ("RIFF", 4); w32 (36 + data); o.write ("WAVEfmt ", 8); w32 (16); w16 (1); w16 (2);
    w32 ((uint32_t) sr); w32 ((uint32_t) sr * 4); w16 (4); w16 (16); o.write ("data", 4); w32 (data);
    for (uint32_t i = 0; i < n; ++i)
        for (float v : { l[i], r[i] }) { int16_t s = (int16_t) std::lround (std::clamp (v, -1.0f, 1.0f) * 32767.0f); o.write ((char*) &s, 2); }
}

int main (int argc, char** argv)
{
    if (argc < 4) { std::cerr << "usage : rendu entree.wav sortie.wav scenario.txt\n"; return 1; }
    std::vector<float> L, R; int sr = 48000;
    if (! lireWav (argv[1], L, R, sr)) { std::cerr << "lecture impossible\n"; return 1; }

    sfx::Engine e;
    if (! e.allZonesFound()) { std::cerr << "commandes Faust introuvables\n"; return 1; }
    const auto& defs = e.getParams();
    struct Evt { double t; size_t i; float v; };
    std::vector<Evt> evts;
    std::ifstream sc (argv[3]); std::string line;
    while (std::getline (sc, line))
    {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream ss (line); double t; ss >> t; std::string kv;
        while (ss >> kv)
        {
            auto p = kv.find ('='); auto id = kv.substr (0, p); float v = std::stof (kv.substr (p + 1));
            size_t i = 0; while (i < defs.size() && defs[i].id != id) ++i;
            if (i == defs.size()) { std::cerr << "réglage inconnu : " << id << "\n"; return 1; }
            evts.push_back ({ t, i, v });
        }
    }
    for (auto& ev : evts) if (ev.t <= 0) e.setParam (ev.i, ev.v);
    e.prepare (sr);

    const int bloc = 256; size_t next = 0;
    int nan = 0; double pic = 0;
    std::vector<double> rmsSec;
    double acc = 0; int cnt = 0;
    for (size_t pos = 0; pos < L.size(); pos += bloc)
    {
        const double t = (double) pos / sr;
        while (next < evts.size() && evts[next].t <= t) { if (evts[next].t > 0) e.setParam (evts[next].i, evts[next].v); ++next; }
        const int k = (int) std::min<size_t> (bloc, L.size() - pos);
        e.setTempo (100.0, true, t * 100.0 / 60.0);   // source à 100 BPM
        e.process (&L[pos], &R[pos], k);
        for (int i = 0; i < k; ++i)
            for (float v : { L[pos + i], R[pos + i] })
            {
                if (! std::isfinite (v)) ++nan;
                pic = std::max (pic, (double) std::abs (v));
                acc += v * v; ++cnt;
                if (cnt == 2 * sr) { rmsSec.push_back (10 * std::log10 (acc / cnt + 1e-20)); acc = 0; cnt = 0; }
            }
    }
    std::printf ("latence %d échantillons, crête %.2f dBFS, NaN %d\nRMS par seconde (dBFS) :", e.latency(), 20 * std::log10 (pic + 1e-20), nan);
    for (double v : rmsSec) std::printf (" %.0f", v);
    std::printf ("\n");
    ecrireWav (argv[2], L, R, sr);
    return nan ? 2 : 0;
}
