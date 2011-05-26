#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "Voiture.h"
#include "Carrefour.h"


/**
 * File de véhicules (une par segment)
 */
typedef struct {
    int id;
    struct File * voitureAvant;
    Voiture * voiture;
    struct File * voitureApres;
} File;


/**
 * Chemins et tracés
 */
//int * Chemins[21][21];


#endif // STRUCTURES_H_INCLUDED

