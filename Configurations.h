#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include "Voiture.h"
#include "Segment.h"

/*int longueurRoutes = 500;
int largeurRoutes = 40;
int espaceRoutes = 95; // espaceRoutes = (longueurRoutes - 3*largeurRoutes) / 4
int padding = 40;
int vitesseMax;*/

void init_config(ListeSegments listeSegments, ListeCarrefours listeCarrefours, Traces traces, int *** chemins, int padding, int espaceRoutes, int largeurRoutes);

/*int *** chemins;
int traces[62][5];*/

#endif // CONFIGURATIONS_H
