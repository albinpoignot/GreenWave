#include <stdio.h>
#include <stdlib.h>

#include "Structures.h"
#include "Carrefour.h"
#include "Voiture.h"
#include "Feu.h"

int longueurRoutes = 500;
int largeurRoutes = 40;
int espaceRoutes = 95; // espaceRoutes = (longueurRoutes - 3*largeurRoutes) / 4
int padding = 40;

void init_config()
{
    // Phase 1 : Initialisation des carrefours
    Carrefour * carrefour0 = Carrefour_init(0, padding, 0);
    Carrefour * carrefour1 = Carrefour_init(1, carrefour0->posX + espaceRoutes + largeurRoutes, 0);
    Carrefour * carrefour2 = Carrefour_init(2, carrefour1->posX + espaceRoutes + largeurRoutes, 0);

    Carrefour * carrefour3 = Carrefour_init(3, 0, padding + espaceRoutes);
    Carrefour * carrefour4 = Carrefour_init(4, espaceRoutes + largeurRoutes, carrefour3->posY);
    Carrefour * carrefour5 = Carrefour_init(5, carrefour4->posX + espaceRoutes + largeurRoutes, carrefour3->posY);
    Carrefour * carrefour6 = Carrefour_init(6, carrefour5->posX + espaceRoutes + largeurRoutes, carrefour3->posY);
    Carrefour * carrefour7 = Carrefour_init(7, carrefour6->posX + espaceRoutes + largeurRoutes, carrefour3->posY);

    Carrefour * carrefour8 = Carrefour_init(8, 0, padding + espaceRoutes + carrefour3->posY);
    Carrefour * carrefour9 = Carrefour_init(9, espaceRoutes + largeurRoutes, carrefour8->posY);
    Carrefour * carrefour10 = Carrefour_init(10, carrefour9->posX + espaceRoutes + largeurRoutes, carrefour8->posY);
    Carrefour * carrefour11 = Carrefour_init(11, carrefour10->posX + espaceRoutes + largeurRoutes, carrefour8->posY);
    Carrefour * carrefour12 = Carrefour_init(12, carrefour11->posX + espaceRoutes + largeurRoutes, carrefour8->posY);

    Carrefour * carrefour13 = Carrefour_init(13, 0, padding + espaceRoutes + carrefour8->posY);
    Carrefour * carrefour14 = Carrefour_init(14, espaceRoutes + largeurRoutes, carrefour8->posY);
    Carrefour * carrefour15 = Carrefour_init(15, carrefour14->posX + espaceRoutes + largeurRoutes, carrefour13->posY);
    Carrefour * carrefour16 = Carrefour_init(16, carrefour15->posX + espaceRoutes + largeurRoutes, carrefour13->posY);
    Carrefour * carrefour17 = Carrefour_init(17, carrefour16->posX + espaceRoutes + largeurRoutes, carrefour13->posY);

    Carrefour * carrefour18 = Carrefour_init(18, padding, padding + espaceRoutes + carrefour13->posY);
    Carrefour * carrefour19 = Carrefour_init(19, carrefour18->posX + espaceRoutes + largeurRoutes, carrefour18->posY);
    Carrefour * carrefour20 = Carrefour_init(20, carrefour19->posX + espaceRoutes + largeurRoutes, carrefour18->posY);

    // Phase 2 : Initialisation des segments
    // Segments verticaux
*/
/*    ListeSegments[0][4] = Segment_init(Carrefour_init(0),Carrefour_init(4));
    ListeSegments[4][0] = Segment_init(Carrefour_init(4),Carrefour_init(0));
    ListeSegments[4][9] = Segment_init(Carrefour_init(4),Carrefour_init(9));
    ListeSegments[9][4] = Segment_init(Carrefour_init(9),Carrefour_init(4));
    ListeSegments[9][14] = Segment_init(Carrefour_init(9),Carrefour_init(14));
    ListeSegments[14][9] = Segment_init(Carrefour_init(14),Carrefour_init(9));
    ListeSegments[14][18] = Segment_init(Carrefour_init(14),Carrefour_init(18));
    ListeSegments[18][14] = Segment_init(Carrefour_init(18),Carrefour_init(14));

    ListeSegments[0][4] = Segment_init(carrefour0,carrefour4);
    ListeSegments[4][0] = Segment_init(carrefour4,carrefour0);
    ListeSegments[4][9] = Segment_init(carrefour4,carrefour9);
    ListeSegments[9][4] = Segment_init(carrefour9,carrefour4);
    ListeSegments[9][14] = Segment_init(carrefour9,carrefour14);
    ListeSegments[14][9] = Segment_init(carrefour14,carrefour9);
    ListeSegments[14][18] = Segment_init(carrefour14,carrefour18);
    ListeSegments[18][14] = Segment_init(carrefour18,carrefour14);

    ListeSegments[1][5] = Segment_init(carrefour1,carrefour5);
    ListeSegments[5][1] = Segment_init(carrefour5,carrefour1);
    ListeSegments[5][10] = Segment_init(carrefour5,carrefour10);
    ListeSegments[10][5] = Segment_init(carrefour10,carrefour5);
    ListeSegments[10][15] = Segment_init(carrefour10,carrefour15);
    ListeSegments[15][10] = Segment_init(carrefour15,carrefour10);
    ListeSegments[15][19] = Segment_init(carrefour15,carrefour19);
    ListeSegments[19][15] = Segment_init(carrefour19,carrefour15);

    ListeSegments[2][6] = Segment_init(carrefour12,carrefour6);
    ListeSegments[6][2] = Segment_init(carrefour6,carrefour2);
    ListeSegments[6][11] = Segment_init(carrefour6,carrefour11);
    ListeSegments[11][6] = Segment_init(carrefour11,carrefour6);
    ListeSegments[11][16] = Segment_init(carrefour11,carrefour16);
    ListeSegments[16][11] = Segment_init(carrefour16,carrefour11);
    ListeSegments[16][20] = Segment_init(carrefour16,carrefour20);
    ListeSegments[20][16] = Segment_init(carrefour20,carrefour16);

    // Segments horizontaux
    ListeSegments[3][4] = Segment_init(carrefour3,carrefour4);
    ListeSegments[4][3] = Segment_init(carrefour4,carrefour3);
    ListeSegments[4][5] = Segment_init(carrefour4,carrefour5);
    ListeSegments[5][4] = Segment_init(carrefour5,carrefour4);
    ListeSegments[5][6] = Segment_init(carrefour5,carrefour6);
    ListeSegments[6][5] = Segment_init(carrefour6,carrefour5);
    ListeSegments[6][7] = Segment_init(carrefour6,carrefour7);
    ListeSegments[7][6] = Segment_init(carrefour7,carrefour6);

    ListeSegments[8][9] = Segment_init(carrefour8,carrefour9);
    ListeSegments[9][8] = Segment_init(carrefour9,carrefour8);
    ListeSegments[9][10] = Segment_init(carrefour9,carrefour10);
    ListeSegments[10][9] = Segment_init(carrefour10,carrefour9);
    ListeSegments[10][11] = Segment_init(carrefour10,carrefour11);
    ListeSegments[11][10] = Segment_init(carrefour11,carrefour10);
    ListeSegments[11][12] = Segment_init(carrefour11,carrefour12);
    ListeSegments[12][11] = Segment_init(carrefour12,carrefour11);

    ListeSegments[13][14] = Segment_init(carrefour13,carrefour14);
    ListeSegments[14][13] = Segment_init(carrefour14,carrefour13);
    ListeSegments[14][15] = Segment_init(carrefour14,carrefour15);
    ListeSegments[15][14] = Segment_init(carrefour15,carrefour14);
    ListeSegments[15][16] = Segment_init(carrefour15,carrefour16);
    ListeSegments[16][15] = Segment_init(carrefour16,carrefour15);
    ListeSegments[16][17] = Segment_init(carrefour16,carrefour17);
    ListeSegments[17][16] = Segment_init(carrefour17,carrefour16);

    // Phase 3 : Initialisation des chemins possibles
    int i;
    traces = (int **) malloc(61 * sizeof(int*));
    for(i=0; i<=61; i++)
    {
        traces[i] = (int *)malloc(5 * sizeof(int));
    }

    traces[0] = {4};
    traces[1] = {4,5};
    traces[2] = {4,5,6};
    traces[3] = {4,5,6,11};
    traces[4] = {4,5,6,11,16};
    traces[5] = {4,5,10,15};
    traces[6] = {4,5,10,11,16};
    traces[7] = {4,5,10,15,16};
    traces[8] = {4,9};
    traces[9] = {4,9,10,11};
    traces[10] = {4,9,10,11,16};
    traces[11] = {4,9,10,15};
    traces[12] = {4,9,10,15,16};
    traces[13] = {4,5};
    traces[14] = {4,9,14};
    traces[15] = {4,9,14,15};
    traces[16] = {4,9,14,15,16};

    traces[17] = {5,4,9};
    traces[18] = {5,4,9,14};
    traces[19] = {5,6};
    traces[20] = {5,6,11};
    traces[21] = {5,6,11,16};
    traces[22] = {5,10,9};
    traces[23] = {5,10,9,14};
    traces[24] = {5,10,11};
    traces[25] = {5,10,11,16};
    traces[26] = {5,10,15};
    traces[27] = {5,10,15,14};
    traces[28] = {5,10,15,16};

    traces[29] = {6};
    traces[30] = {6,5,4,9};
    traces[31] = {6,5,4,9,14};
    traces[32] = {6,5,10,9};
    traces[33] = {6,5,10,9,14};
    traces[34] = {6,5,10,15};
    traces[35] = {6,5,10,15,14};
    traces[36] = {6,11};
    traces[37] = {6,11,10,9};
    traces[38] = {6,11,10,15};
    traces[39] = {6,11,10,9,14};
    traces[40] = {6,11,10,15,14};
    traces[41] = {6,11,16};
    traces[42] = {6,11,16,15,14};
    traces[43] = {6,11,16,15};

    traces[44] = {9,10,11};
    traces[45] = {9,10,11,16};
    traces[46] = {9,10,15};
    traces[47] = {9,14};
    traces[48] = {9,14,15};
    traces[49] = {9,10,15,16};
    traces[50] = {9,14,15,16};

    traces[51] = {11,10,9,14};
    traces[52] = {11,10,15};
    traces[53] = {11,10,15,14};
    traces[54] = {11,16};
    traces[55] = {11,16,15};
    traces[56] = {11,16,15,14};

    traces[57] = {14};
    traces[58] = {14,5};
    traces[59] = {14,15,16};

    traces[60] = {15,16};

    traces[61] = {16};

}
