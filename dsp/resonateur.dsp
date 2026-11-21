// SpectralFX — partie « résonateur sale » (Faust).
// Entrée : le signal déjà passé par le « spectre brisé » (partie C++ à base de FFT,
// voir src/Spectre.h). Sortie : ce signal mélangé à 4 résonateurs (cordes ou tubes
// métalliques virtuels) accordés sur une note et un accord, puis saturés.
//
// Ce fichier fonctionne seul dans https://faustide.grame.fr (il résonne sur
// l'entrée audio), mais sans la partie spectrale.

import("stdfaust.lib");
declare name "SpectralFX";
declare author "Ali";

// ---------------------------------------------------------------- commandes
note    = hslider("Résonateur/Note", 40, 24, 84, 1) : si.smooth(ba.tau2pole(0.04));
accord  = nentry("Résonateur/Accord", 2, 0, 6, 1);
tube    = checkbox("Résonateur/Tube");
t60     = hslider("Résonateur/Résonance", 3, 0.2, 20, 0.01) : si.smoo;
brill   = hslider("Résonateur/Brillance", 0.6, 0, 1, 0.01) : si.smoo;
metal   = hslider("Résonateur/Métal", 0.2, 0, 1, 0.01) : si.smoo;
derive  = hslider("Résonateur/Dérive", 0.3, 0, 1, 0.01) : si.smoo;
salete  = hslider("Couleur/Saleté", 0.3, 0, 1, 0.01) : si.smoo;
part    = hslider("Couleur/Part du résonateur", 0.7, 0, 1, 0.01) : si.smoo;

// ---------------------------------------------------------------- accords
// intervalles (demi-tons) des 4 résonateurs pour chaque accord
// 0 Unisson, 1 Octaves, 2 Quinte, 3 Majeur, 4 Mineur, 5 Sus4, 6 Dissonant
// (notés +12 pour éviter les nombres négatifs ; une liste par résonateur,
//  dans l'ordre des accords)
voix(0) = (12,    0,  12, 12, 12, 12, 12);
voix(1) = (12.04, 12, 19, 16, 15, 17, 13);
voix(2) = (11.96, 24, 24, 19, 19, 19, 18);
voix(3) = (12.02, 36, 31, 24, 24, 24, 23);
intervalle(v) = ba.selectn(7, int(accord), voix(v)) - 12
              : si.smooth(ba.tau2pole(0.05));   // glissé doux quand on change d'accord

// ---------------------------------------------------------------- dérive
// lente variation aléatoire de l'accord + écart gauche/droite (largeur stéréo)
vitesses = (0.17, 0.23, 0.29, 0.37, 0.19, 0.31, 0.41, 0.13);
derivee(v, ch) = derive * (0.3 * no.lfnoiseN(2, ba.take(v + 4 * ch + 1, vitesses))
                         + 0.07 * (2 * ch - 1) * (v + 1) / 4);

freq(v, ch) = ba.midikey2hz(note + intervalle(v) + derivee(v, ch));

// ---------------------------------------------------------------- un résonateur
// boucle : retard (accord) -> passe-tout (métal : partiels étirés, son de cloche)
//          -> filtre (brillance) -> saturation douce (la boucle reste stable)
maxd = 16384;
ap1(a, x) = (\(yp).(a * x + x' - a * yp)) ~ _;
resonateur(f) = *(norme) : (+ : de.fdelay3(maxd, dly) : ap1(a) : ap1(a) : ap1(a) : ap1(a)
                              : fi.lowpass(1, fc) : boucleSat) ~ *(g * signe)
with {
    periode = ma.SR / f / (1 + tube);             // tube : demi-longueur, harmoniques impaires
    a = -0.8 * metal;
    retardAp = 4 * (1 - a) / (1 + a);             // retard propre des passe-tout
    dly = max(2, periode - 1 - retardAp);
    fc = min(300 * pow(2, brill * 6), ma.SR * 0.45);
    g = pow(10, -3 * periode / (t60 * ma.SR));    // durée de résonance (temps de chute à -60 dB)
    signe = 1 - 2 * tube;
    norme = sqrt(1 - g * g);
    boucleSat(x) = 2 * ma.tanh(0.5 * x);
};

// ---------------------------------------------------------------- saturation
sature(x) = (ma.tanh(x * drv + b) - ma.tanh(b)) / pow(drv, 0.55)
          : fi.dcblocker : fi.lowpass(2, 16000 - 8000 * salete)
with {
    drv = ba.db2linear(salete * 30);
    b = 0.25 * salete;
};

resonance(ch) = _ <: par(v, 4, resonateur(freq(v, ch))) :> *(0.5) : sature;

voie(ch) = _ <: *(1 - part), (resonance(ch) : *(part)) :> _;

process = voie(0), voie(1);
