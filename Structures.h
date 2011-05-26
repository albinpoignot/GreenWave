#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include "Voiture.h"
//#include "Feu.h"

/**
 * Carrefours et leur liste
 */
typedef struct {
    int id;
    int posX;
    int posY;
    // Feu
} Carrefour;

Carrefour * ListeCarrefours[21];

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
 * Segment de route (1 par sens de circulation)
 *  -> relie deux carrefours entre eux
 */
typedef struct {
    Carrefour * carrefourEntree;
    Carrefour * carrefourSortie;
    File * file;
} Segment;

Segment * ListeSegments[21][21];

/**
 * Chemins et tracés
 */
int Chemins[21][21];
int ** traces;

/*chemins[0][1] =
chemins[0][2] =
chemins[0][3] =
chemins[0][7] =
chemins[0][8] =
chemins[0][12] =
chemins[0][13] =
chemins[0][17] =
chemins[0][18] =
chemins[0][19] =
chemins[0][20] =

chemins[1][2] =
chemins[1][3] =
chemins[1][7] =
chemins[1][8] =
chemins[1][12] =
chemins[1][13] =
chemins[1][17] =
chemins[1][18] =
chemins[1][19] =
chemins[1][20] =

chemins[2][3] =
chemins[2][7] =
chemins[2][8] =
chemins[2][12] =
chemins[2][13] =
chemins[2][17] =
chemins[2][18] =
chemins[2][19] =
chemins[2][20] =

chemins[3][7] =
chemins[3][8] =
chemins[3][12] =
chemins[3][13] =
chemins[3][17] =
chemins[3][18] =
chemins[3][19] =
chemins[3][20] =

chemins[7][8] =
chemins[7][12] =
chemins[7][13] =
chemins[7][17] =
chemins[7][18] =
chemins[7][19] =
chemins[7][20] =

chemins[8][12] =
chemins[8][13] =
chemins[8][17] =
chemins[8][18] =
chemins[8][19] =
chemins[8][20] =

chemins[12][13] =
chemins[12][17] =
chemins[12][18] =
chemins[12][19] =
chemins[12][20] =

chemins[13][17] =
chemins[13][18] =
chemins[13][19] =
chemins[13][20] =

chemins[17][18] =
chemins[17][19] =
chemins[17][20] =

chemins[18][19] =
chemins[18][20] =

chemins[19][20] =*/

/**
 * En tetes de fonction
 */
Carrefour * Carrefour_init(int id, int posX, int posY);
Segment * Segment_init(Carrefour * carEnt, Carrefour * carSor);



#endif // STRUCTURES_H_INCLUDED
