#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "Voiture.h"
//#include "Feu.h"

typedef struct {
    int id;
    int posX;
    int posY;
    // Feu
} Carrefour;

Carrefour * ListeCarrefours[21];

// File : liste doublement chainée
typedef struct {
    int id;
    struct File * voitureAvant;
    Voiture * voiture;
    struct File * voitureApres;
} File;


typedef struct {
    Carrefour * carrefourEntree;
    Carrefour * carrefourSortie;
    File * file;
} Segment;

Segment * ListeSegments[21][21];



Carrefour * Carrefour_init(int id, int posX, int posY);
Segment * Segment_init(Carrefour * carEnt, Carrefour * carSor);



#endif // STRUCTURES_H_INCLUDED
