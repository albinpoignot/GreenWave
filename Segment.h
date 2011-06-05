#ifndef SEGMENT_H
#define SEGMENT_H

#include "Carrefour.h"

#define MAX_CARREFOUR 21
//#include "Voiture.h" <- Est inclut plus loin dans le fichier pour permettre de faire certains typedef avant

/**
 * Segment de route (1 par sens de circulation)
 *  -> relie deux carrefours entre eux
 */
typedef struct Segment Segment;

struct Segment {
    Carrefour * carrefourEntree;
    Carrefour * carrefourSortie;
    struct File * file;
};

typedef int Traces[62][5];
typedef Segment * ListeSegments[MAX_CARREFOUR][MAX_CARREFOUR];
//typedef int ListeSegments;


#include "Voiture.h"
/**
 * File de véhicules (une par segment)
 */
typedef struct File File;
struct File {
    int id;
    struct Voiture * voitureAvant;
    struct Voiture * voiture;
    struct Voiture * voitureApres;
};

//Segment * listeSegments[MAX_CARREFOUR][MAX_CARREFOUR];
Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour4);

#endif // SEGMENT_H
