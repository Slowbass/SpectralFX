# SpectralFX : notice d'utilisation

SpectralFX transforme n'importe quel son (guitare, basse, batterie…) en drones métalliques et en textures accordées. Le son traverse trois étapes, de gauche à droite : **Spectre**, puis **Résonateur**, puis **Sortie**. La section **Mouvement** fait bouger certains réglages tout seuls.

Double-clic sur un bouton : retour à sa position par défaut.

## Spectre : déformer le son

Le plugin sépare le son en ses différentes fréquences (graves, médiums, aigus…), puis il les déplace, les prolonge ou les fige.

| Commande | Ce qu'elle fait | Quand l'utiliser |
|---|---|---|
| **Geler** | Fige le son du moment et le tient sans fin, comme une note tenue. | Appuie sur un accord ou un coup de cymbale pour en faire un drone. |
| **Traîne** | Chaque fréquence met plus longtemps à s'éteindre (jusqu'à 12 s). Le son devient un nuage, un peu comme une réverbération. | Pour lisser et étaler. Vers 2 à 4 s, c'est déjà très planant. |
| **Décalage** | Ajoute le même nombre de Hz à toutes les fréquences. Les harmoniques ne « s'accordent » plus entre elles. | Le bouton clé du son métallique, de cloche, de radio. Quelques dizaines de Hz suffisent. |
| **Étirement** | Multiplie toutes les fréquences. Au-dessus de ×1, le son s'écarte et devient étrange et cristallin. En dessous, il se resserre et s'assombrit. | Pour tordre le timbre sans le décaler. |
| **Brisure** | Éparpille des fréquences au hasard, et elles changent sans arrêt. | Pour un son cassé et scintillant. À fond, c'est le chaos. |
| **Épure** | Ne garde que les fréquences les plus fortes. Le son devient plus pur, sifflant, presque électronique. | Pour une batterie ou un son trop chargé. |

## Résonateur : faire chanter le son

Quatre cordes ou tubes virtuels sont « frappés » par le son et résonnent sur une note.

| Commande | Ce qu'elle fait |
|---|---|
| **Note** | La note de base des résonateurs. Choisis la tonalité du morceau (Do3 = do du milieu, comme dans Cubase). |
| **Accord** | Comment les 4 résonateurs s'accordent : Unisson (une seule note épaisse), Octaves, Quinte (son « puissant »), Majeur, Mineur, Sus4 (suspendu, ni gai ni triste), Dissonant (tendu, inquiétant). |
| **Matière** | **Corde** : son plein, riche. **Tube** : son plus creux, boisé, comme une clarinette ou un tuyau. |
| **Résonance** | Durée de la résonance, de 0,2 s (petit choc) à 20 s (drone qui ne s'arrête plus). |
| **Brillance** | À gauche, résonance sombre et feutrée. À droite, brillante et vive. |
| **Métal** | Rend les harmoniques inégales : on passe de la corde à la cloche, puis à la plaque de métal. |
| **Dérive** | Les résonateurs se désaccordent lentement au hasard et s'écartent en stéréo. Ça donne de la vie et de la largeur. |

## Sortie

| Commande | Ce qu'elle fait |
|---|---|
| **Saleté** | Saturation des résonateurs, de la chaleur légère jusqu'à la distorsion franche. |
| **Résonateur** | Dosage entre le spectre seul (à gauche) et le son des résonateurs (à droite). |
| **Sec / traité** | Mélange avec le son d'origine. À 0 %, le son est intact. À 100 %, seul l'effet est audible. |
| **Volume** | Volume de sortie, pour compenser si l'effet est trop fort ou trop faible. |

## Mouvement : le son évolue tout seul

Un « modulateur » invisible fait varier certains réglages en boucle, sans automatisation. Le petit curseur à côté du titre MOUVEMENT montre où il en est.

| Commande | Ce qu'elle fait |
|---|---|
| **Rythme** | **Tempo** : le mouvement suit le tempo de Cubase. **Libre** : il suit sa propre vitesse. |
| **Durée** (en mode Tempo) | Longueur d'un cycle, de 1/16 à 8 mesures. |
| **Vitesse** (en mode Libre) | De 0,02 Hz (un cycle toutes les 50 s) à 5 Hz (rapide). |
| **Forme** | **Sinus** et **Triangle** : va-et-vient régulier. **Hasard doux** : glisse vers une nouvelle valeur au hasard. **Hasard net** : saute à chaque cycle, idéal pour des notes aléatoires en rythme. |
| **Regel** | Quand Geler est actif, le son est figé à nouveau à chaque cycle. Le drone se renouvelle en rythme. |
| **→ Décalage, → Étirement, → Brisure, → Note, → Saleté** | Quantité de mouvement envoyée vers chaque réglage. Au centre, rien ne bouge. Vers la droite, l'effet augmente. Vers la gauche, il agit à l'envers. **→ Note** va jusqu'à ±12 demi-tons. |

## Réglages de départ conseillés

Pars des réglages par défaut (double-clic sur chaque bouton), puis :

1. **Drone de guitare** : joue un accord, Traîne 3 s, Accord Quinte, Note dans la tonalité, Résonance 6 s. Active **Geler** quand l'accord sonne bien. Sec / traité à 100 %.
2. **Cloches métalliques** : Décalage +80 Hz, Métal 60 %, Accord Dissonant, Brillance 80 %, Résonance 4 s.
3. **Batterie qui chante** : sur la piste room ou overheads, mets Épure à 50 %, Matière Tube, Accord Mineur, Résonance 1 s, Saleté 50 % et Sec / traité à 40 %. Les frappes déclenchent des notes.
4. **Texture qui respire** : Traîne 2 s, Rythme Tempo, Durée 2 mesures, Forme Sinus, → Décalage +30 % et → Étirement +20 %.
5. **Mélodie aléatoire** : Matière Tube, Rythme Tempo, Durée 1/4, Forme Hasard net, → Note +50 % et → Saleté +60 %.

## Bon à savoir

- Le plugin ajoute environ 43 ms de retard, que Cubase compense automatiquement.
- Tout est automatisable dans Cubase.
- Avec une longue Résonance et Saleté à fond, le volume peut monter : garde un œil sur le niveau de sortie.
