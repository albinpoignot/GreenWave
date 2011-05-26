/*#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "Voiture.h"
#include "Feu.h"
#include "Carrefour.h"


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

Segment * listeSegments[MAX_CARREFOUR][MAX_CARREFOUR];




Segment * segment_init(Carrefour * carEnt, Carrefour * carSor);



#endif // STRUCTURES_H_INCLUDED
*/
