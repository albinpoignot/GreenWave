#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include "Voiture.h"
#include "Segment.h"

void init_config(ListeSegments listeSegments, ListeCarrefours listeCarrefours, Traces traces, int *** chemins,
                 int padding, int espaceRoutes, int largeurRoutes);

void init_listeCarrefours(ListeCarrefours listeCarrefours, int padding, int espaceRoutes, int largeurRoutes);
void init_listeSegments(ListeSegments listeSegments, ListeCarrefours listeCarrefours);
void init_traces(Traces traces);
void init_chemins(Chemins chemins);

void destroy_listeCarrefours(ListeCarrefours listeCarrefours);
void destroy_listeSegments(ListeSegments listeSegments);

#endif // CONFIGURATIONS_H
