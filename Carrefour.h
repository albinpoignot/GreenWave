#ifndef CARREFOUR_H_INCLUDED
#define CARREFOUR_H_INCLUDED

#include "Feu.h"

#define MAX_CARREFOUR 21
#define MAX_FEU 4

typedef struct {
    int id;
    int posX;
    int posY;
    Feu tabFeux[MAX_FEU];
} Carrefour;


typedef Carrefour listeCarrefours[MAX_CARREFOUR];

// Carrefour * ListeCarrefours[21];

// Prototypes des fonctions de Carrefour.c

// Initialisation et destruction d'un carrefour
Carrefour * carrefour_init(int id, int posX, int posY);
void carrefour_destroy(Carrefour carrefour);

// Détection et correction des erreurs de synchronisation des feux d'un carrefour
void carrefour_detecterErreur(Carrefour carrefour);

// Si l'ordonnancement aléatoire est choisi, cette fonction initialise la couleur des feux de manière aléatoire et corrige les erreurs de synchronisation
void carrefour_ordoAlea(listeCarrefours tableauCarrefours);

// Si l'ordonnancement Vague Verte est choisi, cette fonction initialise la couleur des feux de sorte à permettre une vague verte.
// Elle corrige également les erreurs de synchronisation
void carrefour_ordoVagueVerte(Carrefour ** tableauCarrefours);

#endif // CARREFOUR_H_INCLUDED

