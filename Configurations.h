#include "Segment.h"

void init_config();

int longueurRoutes;
int largeurRoutes;
int espaceRoutes; // espaceRoutes = (longueurRoutes - 3*largeurRoutes) / 4
int padding;

int *** chemins;
int traces[62][5];
