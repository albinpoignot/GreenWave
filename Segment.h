#ifndef SEGMENT_H
#define SEGMENT_H

#include "Carrefour.h"
#include "Segment.h"
#include "Voiture.h"

/**
 * Segment de route (1 par sens de circulation)
 *  -> relie deux carrefours entre eux
 */
typedef struct {
    Carrefour * carrefourEntree;
    Carrefour * carrefourSortie;
    struct File * file;
} Segment;

/**
 * File de véhicules (une par segment)
 */
typedef struct {
    int id;
    struct File * voitureAvant;
    struct Voiture * voiture;
    struct File * voitureApres;
} File;

typedef int Traces[62][5];

typedef Segment ListeSegments[MAX_CARREFOUR][MAX_CARREFOUR][1];

//Segment * listeSegments[MAX_CARREFOUR][MAX_CARREFOUR];
Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour4);

#endif // SEGMENT_H
