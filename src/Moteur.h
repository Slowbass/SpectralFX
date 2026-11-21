// SpectralFX — moteur audio complet, indépendant de JUCE :
//   entrée -> spectre brisé (C++, src/Spectre.h) -> résonateurs saturés (Faust, dsp/resonateur.dsp)
//   puis mélange avec le son sec (retardé de la même latence) et volume de sortie.
#pragma once

#include "FaustBase.h"
#if defined (_MSC_VER)
 #pragma warning (push, 0)
#elif defined (__clang__)
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Weverything"
#elif defined (__GNUC__)
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
 #pragma GCC diagnostic ignored "-Wfloat-equal"
 #pragma GCC diagnostic ignored "-Wunused-parameter"
 #pragma GCC diagnostic ignored "-Wconversion"
 #pragma GCC diagnostic ignored "-Wsign-conversion"
 #pragma GCC diagnostic ignored "-Wshadow"
 #pragma GCC diagnostic ignored "-Wunused-variable"
 #pragma GCC diagnostic ignored "-Wdouble-promotion"
#endif
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include "../generated/FaustResonateur.h"
#if defined (_MSC_VER)
 #pragma warning (pop)
#elif defined (__clang__)
 #pragma clang diagnostic pop
#elif defined (__GNUC__)
 #pragma GCC diagnostic pop
#endif

#include "Spectre.h"
#include <atomic>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace sfx
{

enum class Kind { Toggle, Percent, Traine, Hz, Rapport, Note, Accord, Secondes, Db, Vitesse, Division, Forme, Quantite };
enum class Cible { Spectre, Faust, Moteur };

struct ParamDef
{
    std::string id;         // identifiant stable (automation, presets)
    std::string name;       // nom affiché dans Cubase (UTF-8)
    Kind kind;
    Cible cible;
    std::string faustPath;  // chemin de la commande dans le code Faust (si cible Faust)
    float min = 0, max = 1, init = 0;
    float step = 0;         // 1 pour les valeurs entières
    float centre = 0;       // valeur au milieu de la course (0 = course linéaire)
    bool symetrique = false;
};

enum Index
{
    pGeler, pTraine, pDecalage, pEtirement, pBrisure, pEpure,
    pNote, pAccord, pTube, pResonance, pBrillance, pMetal, pDerive,
    pSalete, pPart, pMelange, pSortie,
    pSync, pVitesse, pDivision, pForme, pRegel,
    pModDecalage, pModEtirement, pModBrisure, pModNote, pModSalete, nbParams
};

inline std::vector<ParamDef> makeParams()
{
    std::vector<ParamDef> v (nbParams);
    v[pGeler]      = { "geler", "Geler", Kind::Toggle, Cible::Spectre, "", 0, 1, 0 };
    v[pTraine]     = { "traine", "Tra\xc3\xae" "ne", Kind::Traine, Cible::Spectre, "", 0, 1, 0.4f };
    v[pDecalage]   = { "decalage", "D\xc3\xa9" "calage", Kind::Hz, Cible::Spectre, "", -1000, 1000, 0, 0, 0, true };
    v[pEtirement]  = { "etirement", "\xc3\x89tirement", Kind::Rapport, Cible::Spectre, "", 0.5f, 2.0f, 1.0f, 0, 1.0f };
    v[pBrisure]    = { "brisure", "Brisure", Kind::Percent, Cible::Spectre, "", 0, 1, 0 };
    v[pEpure]      = { "epure", "\xc3\x89pure", Kind::Percent, Cible::Spectre, "", 0, 1, 0 };
    v[pNote]       = { "note", "Note", Kind::Note, Cible::Faust, "R\xc3\xa9sonateur/Note", 24, 84, 40, 1 };
    v[pAccord]     = { "accord", "Accord", Kind::Accord, Cible::Faust, "R\xc3\xa9sonateur/Accord", 0, 6, 2, 1 };
    v[pTube]       = { "tube", "Mati\xc3\xa8re (corde / tube)", Kind::Toggle, Cible::Faust, "R\xc3\xa9sonateur/Tube", 0, 1, 0 };
    v[pResonance]  = { "resonance", "R\xc3\xa9sonance", Kind::Secondes, Cible::Faust, "R\xc3\xa9sonateur/R\xc3\xa9sonance", 0.2f, 20, 3, 0, 3.0f };
    v[pBrillance]  = { "brillance", "Brillance", Kind::Percent, Cible::Faust, "R\xc3\xa9sonateur/Brillance", 0, 1, 0.6f };
    v[pMetal]      = { "metal", "M\xc3\xa9tal", Kind::Percent, Cible::Faust, "R\xc3\xa9sonateur/M\xc3\xa9tal", 0, 1, 0.2f };
    v[pDerive]     = { "derive", "D\xc3\xa9rive", Kind::Percent, Cible::Faust, "R\xc3\xa9sonateur/D\xc3\xa9rive", 0, 1, 0.3f };
    v[pSalete]     = { "salete", "Salet\xc3\xa9", Kind::Percent, Cible::Faust, "Couleur/Salet\xc3\xa9", 0, 1, 0.3f };
    v[pPart]       = { "part", "Part du r\xc3\xa9sonateur", Kind::Percent, Cible::Faust, "Couleur/Part du r\xc3\xa9sonateur", 0, 1, 0.7f };
    v[pMelange]    = { "melange", "Sec / trait\xc3\xa9", Kind::Percent, Cible::Moteur, "", 0, 1, 0.7f };
    v[pSortie]     = { "sortie", "Volume de sortie", Kind::Db, Cible::Moteur, "", -18, 18, 0 };
    // Mouvement : un modulateur lent qui fait varier certains réglages tout seul
    v[pSync]       = { "sync", "Mouvement : cal\xc3\xa9 sur le tempo", Kind::Toggle, Cible::Moteur, "", 0, 1, 1 };
    v[pVitesse]    = { "vitesse", "Mouvement : vitesse libre", Kind::Vitesse, Cible::Moteur, "", 0.02f, 5.0f, 0.25f, 0, 0.3f };
    v[pDivision]   = { "division", "Mouvement : dur\xc3\xa9" "e du cycle", Kind::Division, Cible::Moteur, "", 0, 7, 4, 1 };
    v[pForme]      = { "forme", "Mouvement : forme", Kind::Forme, Cible::Moteur, "", 0, 3, 2, 1 };
    v[pRegel]      = { "regel", "Mouvement : regel \xc3\xa0 chaque cycle", Kind::Toggle, Cible::Moteur, "", 0, 1, 0 };
    v[pModDecalage]  = { "mod_decalage", "Mouvement \xe2\x86\x92 D\xc3\xa9" "calage", Kind::Quantite, Cible::Moteur, "", -1, 1, 0 };
    v[pModEtirement] = { "mod_etirement", "Mouvement \xe2\x86\x92 \xc3\x89tirement", Kind::Quantite, Cible::Moteur, "", -1, 1, 0 };
    v[pModBrisure]   = { "mod_brisure", "Mouvement \xe2\x86\x92 Brisure", Kind::Quantite, Cible::Moteur, "", -1, 1, 0 };
    v[pModNote]      = { "mod_note", "Mouvement \xe2\x86\x92 Note", Kind::Quantite, Cible::Moteur, "", -1, 1, 0 };
    v[pModSalete]    = { "mod_salete", "Mouvement \xe2\x86\x92 Salet\xc3\xa9", Kind::Quantite, Cible::Moteur, "", -1, 1, 0 };
    return v;
}

// Durées de cycle calées sur le tempo, en temps (noires), mesure à 4 temps
inline double divisionTemps (int i)
{
    static const double d[8] = { 0.25, 0.5, 1, 2, 4, 8, 16, 32 };
    return d[std::clamp (i, 0, 7)];
}
inline const char* nomDivision (int i)
{
    static const char* n[8] = { "1/16", "1/8", "1/4", "1/2", "1 mesure", "2 mesures", "4 mesures", "8 mesures" };
    return n[std::clamp (i, 0, 7)];
}
inline const char* nomForme (int i)
{
    static const char* n[4] = { "Sinus", "Triangle", "Hasard doux", "Hasard net" };
    return n[std::clamp (i, 0, 3)];
}

inline const char* nomAccord (int i)
{
    static const char* n[7] = { "Unisson", "Octaves", "Quinte", "Majeur", "Mineur", "Sus4", "Dissonant" };
    return n[std::clamp (i, 0, 6)];
}

// Nom de note à la française, octaves comme dans Cubase (Do3 = note MIDI 60)
inline std::string nomNote (int midi)
{
    static const char* n[12] = { "Do", "Do#", "R\xc3\xa9", "R\xc3\xa9#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si" };
    return std::string (n[((midi % 12) + 12) % 12]) + std::to_string (midi / 12 - 2);
}

inline std::string fmt (const char* f, double x)
{
    char b[64];
    std::snprintf (b, sizeof (b), f, x);
    std::string s (b);
    for (auto& c : s) if (c == '.') c = ',';
    return s;
}

inline double traineSecondes (double t) { return 12.0 * t * t; }

inline std::string formatValue (Kind k, float v)
{
    switch (k)
    {
        case Kind::Toggle:   return v > 0.5f ? "oui" : "non";
        case Kind::Percent:  return fmt ("%.0f %%", v * 100.0);
        case Kind::Traine:   { const double s = traineSecondes (v); return v < 0.005f ? "aucune" : (s < 1 ? fmt ("%.2f s", s) : fmt ("%.1f s", s)); }
        case Kind::Hz:       return std::abs (v) < 0.5f ? "0 Hz" : fmt ("%+.0f Hz", v);
        case Kind::Rapport:  return "\xc3\x97 " + fmt ("%.2f", v);
        case Kind::Note:     { const int m = (int) std::lround (v); return nomNote (m) + " \xc2\xb7 " + fmt ("%.1f Hz", 440.0 * std::pow (2.0, (m - 69) / 12.0)); }
        case Kind::Accord:   return nomAccord ((int) std::lround (v));
        case Kind::Secondes: return v < 1 ? fmt ("%.2f s", v) : fmt ("%.1f s", v);
        case Kind::Db:       return fmt ("%+.1f dB", v);
        case Kind::Vitesse:  return v < 1 ? fmt ("%.2f Hz", v) : fmt ("%.1f Hz", v);
        case Kind::Division: return nomDivision ((int) std::lround (v));
        case Kind::Forme:    return nomForme ((int) std::lround (v));
        case Kind::Quantite: return std::abs (v) < 0.005f ? "0" : fmt ("%+.0f %%", v * 100.0);
    }
    return {};
}

// Retrouve les zones mémoire des commandes Faust par leur chemin.
class ZoneCollector : public UI
{
public:
    std::map<std::string, FAUSTFLOAT*> zones;

    void openTabBox (const char* l) override        { push (l); }
    void openHorizontalBox (const char* l) override { push (l); }
    void openVerticalBox (const char* l) override   { push (l); }
    void closeBox() override                        { if (! path.empty()) path.pop_back(); }
    void addButton (const char* l, FAUSTFLOAT* z) override      { add (l, z); }
    void addCheckButton (const char* l, FAUSTFLOAT* z) override { add (l, z); }
    void addVerticalSlider (const char* l, FAUSTFLOAT* z, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT) override   { add (l, z); }
    void addHorizontalSlider (const char* l, FAUSTFLOAT* z, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT) override { add (l, z); }
    void addNumEntry (const char* l, FAUSTFLOAT* z, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT) override         { add (l, z); }

private:
    std::vector<std::string> path;
    void push (const char* l) { path.push_back (l); }
    void add (const char* l, FAUSTFLOAT* z)
    {
        std::string p;   // on ignore le groupe racine (nom du programme)
        for (size_t i = 1; i < path.size(); ++i) p += path[i] + "/";
        zones[p + l] = z;
    }
};

class Engine
{
public:
    Engine() : params (makeParams())
    {
        dsp = std::make_unique<FaustResonateur>();
        ZoneCollector col;
        dsp->buildUserInterface (&col);
        for (auto& p : params)
        {
            FAUSTFLOAT* z = nullptr;
            if (p.cible == Cible::Faust)
            {
                auto it = col.zones.find (p.faustPath);
                if (it != col.zones.end()) z = it->second;
            }
            zones.push_back (z);
            values.push_back (p.init);
        }
    }

    const std::vector<ParamDef>& getParams() const { return params; }
    bool allZonesFound() const
    {
        for (size_t i = 0; i < params.size(); ++i)
            if (params[i].cible == Cible::Faust && zones[i] == nullptr) return false;
        return true;
    }

    void prepare (double sampleRate)
    {
        dsp->init ((int) sampleRate);
        for (size_t i = 0; i < params.size(); ++i) setParam (i, values[i]);
        canal[0].prepare (sampleRate, 1);
        canal[1].prepare (sampleRate, 2);
        lat = canal[0].latency();
        for (auto& d : sec) d.assign ((size_t) lat, 0.0f);
        secPos = 0;
        melLisse = values[pMelange];
        gainLisse = dbToGain (values[pSortie]);
        lisseCoef = (float) std::exp (-1.0 / (0.02 * sampleRate));
        sr = sampleRate;
        phaseLibre = 0; cycle = -1; hasardPrec = 0; hasardSuiv = 0;
    }

    // Tempo de l'hôte (appelé avant chaque bloc). ppq = position en temps si la lecture tourne.
    void setTempo (double bpm, bool lecture, double ppq)
    {
        tempo = bpm > 1 ? bpm : 120;
        enLecture = lecture;
        ppqDebut = ppq;
    }

    // Valeur actuelle du modulateur (-1..1), pour l'affichage
    float valeurMouvement() const { return lfoAffiche.load(); }

    int latency() const { return lat; }

    void setParam (size_t i, float v)
    {
        if (i >= params.size()) return;
        values[i] = v;
        if (zones[i]) *zones[i] = (FAUSTFLOAT) v;
    }

    // Traite en place, par morceaux de taille fixe
    void process (float* left, float* right, int n)
    {
        if (sec[0].empty()) return;   // pas encore préparé
        const float melCible = values[pMelange];
        const float gainCible = dbToGain (values[pSortie]);

        int pos = 0;
        while (pos < n)
        {
            const int k = std::min (chunk, n - pos);
            const float m = avancerMouvement (pos, k);
            SpectreReglages s = reglagesModules (m);
            float* io[2] = { left + pos, right + pos };
            for (int c = 0; c < 2; ++c)
                for (int i = 0; i < k; ++i)
                {
                    const float x = io[c][i];
                    spec[c][(size_t) i] = canal[c].tick (x, s);
                    float& d = sec[c][(size_t) ((secPos + i) % lat)];
                    secOut[c][(size_t) i] = d;
                    d = x;
                }
            secPos = (secPos + k) % lat;

            FAUSTFLOAT* in[2] = { spec[0].data(), spec[1].data() };
            if (zones[pNote])
                *zones[pNote] = (FAUSTFLOAT) std::clamp (values[pNote] + (float) std::lround (values[pModNote] * m * 12.0f), 12.0f, 96.0f);
            if (zones[pSalete])
                *zones[pSalete] = (FAUSTFLOAT) std::clamp (values[pSalete] + values[pModSalete] * m * 0.6f, 0.0f, 1.0f);
            FAUSTFLOAT* out[2] = { wet[0].data(), wet[1].data() };
            dsp->compute (k, in, out);

            for (int i = 0; i < k; ++i)
            {
                melLisse = melCible + (melLisse - melCible) * lisseCoef;
                gainLisse = gainCible + (gainLisse - gainCible) * lisseCoef;
                for (int c = 0; c < 2; ++c)
                {
                    float y = (secOut[c][(size_t) i] * (1.0f - melLisse) + wet[c][(size_t) i] * melLisse) * gainLisse;
                    if (! std::isfinite (y)) { y = 0.0f; besoinRemise = true; }
                    io[c][i] = y;
                }
            }
            pos += k;
        }
        if (besoinRemise)   // sécurité : jamais de valeur invalide qui reste coincée
        {
            besoinRemise = false;
            dsp->instanceClear();
        }
    }

private:
    // Fait avancer le modulateur sur un morceau de k échantillons ; renvoie sa valeur (-1..1)
    float avancerMouvement (int pos, int k)
    {
        const bool sync = values[pSync] > 0.5f;
        double phase;   // en cycles
        if (sync)
        {
            const double cycleTemps = divisionTemps ((int) std::lround (values[pDivision]));
            const double tempsParEch = tempo / 60.0 / sr;
            if (enLecture)
                phase = (ppqDebut + (pos + 0.5 * k) * tempsParEch) / cycleTemps;
            else
            {
                phaseLibre += k * tempsParEch / cycleTemps;
                phase = phaseLibre;
            }
        }
        else
        {
            phaseLibre += k * values[pVitesse] / sr;
            phase = phaseLibre;
        }
        if (phaseLibre > 1.0e6) phaseLibre -= 1.0e6;

        const long long c = (long long) std::floor (phase);
        const double f = phase - (double) c;
        if (c != cycle)
        {
            if (cycle >= 0 || ! sync || ! enLecture) regelEnAttente = true;
            hasardPrec = (c == cycle + 1) ? hasardSuiv : alea();
            hasardSuiv = alea();
            cycle = c;
        }
        float v = 0;
        switch ((int) std::lround (values[pForme]))
        {
            case 0:  v = (float) std::sin (twoPi * f); break;
            case 1:  v = (float) (f < 0.5 ? 4 * f - 1 : 3 - 4 * f); break;
            case 2:  { const double t = 0.5 - 0.5 * std::cos (3.14159265358979 * f); v = (float) (hasardPrec + (hasardSuiv - hasardPrec) * t); break; }
            default: v = (float) hasardPrec; break;
        }
        lfoAffiche.store (v);
        return v;
    }

    SpectreReglages reglagesModules (float m)
    {
        SpectreReglages s;
        s.geler = values[pGeler] > 0.5f;
        s.traine = values[pTraine];
        s.decalage = std::clamp (values[pDecalage] + values[pModDecalage] * m * 600.0f, -1500.0f, 1500.0f);
        s.etirement = std::clamp (values[pEtirement] * std::pow (2.0f, values[pModEtirement] * m * 0.75f), 0.35f, 2.8f);
        s.brisure = std::clamp (values[pBrisure] + values[pModBrisure] * m * 0.7f, 0.0f, 1.0f);
        s.epure = values[pEpure];
        s.regel = regelEnAttente && values[pRegel] > 0.5f;
        regelEnAttente = false;
        return s;
    }

    double alea()
    {
        graine ^= graine << 13; graine ^= graine >> 17; graine ^= graine << 5;
        return (double) (graine & 0xffffff) / (double) 0x800000 - 1.0;
    }

    double sr = 48000, tempo = 120, ppqDebut = 0, phaseLibre = 0, hasardPrec = 0, hasardSuiv = 0;
    bool enLecture = false, regelEnAttente = false;
    long long cycle = -1;
    uint32_t graine = 0x9e3779b9u;
    std::atomic<float> lfoAffiche { 0.0f };

    static float dbToGain (float db) { return std::pow (10.0f, db / 20.0f); }

    std::vector<ParamDef> params;
    std::vector<FAUSTFLOAT*> zones;
    std::vector<float> values;
    std::unique_ptr<FaustResonateur> dsp;
    SpectreCanal canal[2];
    static constexpr int chunk = 256;
    std::vector<float> spec[2] = { std::vector<float> (chunk), std::vector<float> (chunk) };
    std::vector<float> wet[2] = { std::vector<float> (chunk), std::vector<float> (chunk) };
    std::vector<float> secOut[2] = { std::vector<float> (chunk), std::vector<float> (chunk) };
    std::vector<float> sec[2];
    int lat = 2048, secPos = 0;
    float melLisse = 0.7f, gainLisse = 1.0f, lisseCoef = 0.999f;
    bool besoinRemise = false;
};

} // namespace sfx
