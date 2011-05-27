/*#include <stdio.h>
#include <stdlib.h>*/

#include "Configurations.h"

/**
 * \fn void init_config(ListeSegments listeSegments, Traces traces, int *** chemins)
 * \brief Initialise la liste des segments, des carrefours, des traces et des chemins.
 *          Cette ne doit être appelée qu'une seule fois, au début du programme.
 *
 * \param listeSegments La variable qui contiendra la liste des segments
 * \param traces La variable qui contiendra les traces
 * \param chemins La variable qui contiendra les chemins
 */
void init_config(ListeSegments listeSeg, Traces traces, int *** chemins)
{
    /*// Phase 1 : Initialisation des carrefours
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
printf("here%d\n", 2);
    // Phase 2 : Initialisation des segments
    // Segments verticaux
    listeSegments[0][4] = Segment_init(carrefour0,carrefour4);
    listeSegments[4][0] = Segment_init(carrefour4,carrefour0);
    listeSegments[4][9] = Segment_init(carrefour4,carrefour9);
    listeSegments[9][4] = Segment_init(carrefour9,carrefour4);
    listeSegments[9][14] = Segment_init(carrefour9,carrefour14);
    listeSegments[14][9] = Segment_init(carrefour14,carrefour9);
    listeSegments[14][18] = Segment_init(carrefour14,carrefour18);
    listeSegments[18][14] = Segment_init(carrefour18,carrefour14);

    listeSegments[1][5] = Segment_init(carrefour1,carrefour5);
    listeSegments[5][1] = Segment_init(carrefour5,carrefour1);
    listeSegments[5][10] = Segment_init(carrefour5,carrefour10);
    listeSegments[10][5] = Segment_init(carrefour10,carrefour5);
    listeSegments[10][15] = Segment_init(carrefour10,carrefour15);
    listeSegments[15][10] = Segment_init(carrefour15,carrefour10);
    listeSegments[15][19] = Segment_init(carrefour15,carrefour19);
    listeSegments[19][15] = Segment_init(carrefour19,carrefour15);

    listeSegments[2][6] = Segment_init(carrefour12,carrefour6);
    listeSegments[6][2] = Segment_init(carrefour6,carrefour2);
    listeSegments[6][11] = Segment_init(carrefour6,carrefour11);
    listeSegments[11][6] = Segment_init(carrefour11,carrefour6);
    listeSegments[11][16] = Segment_init(carrefour11,carrefour16);
    listeSegments[16][11] = Segment_init(carrefour16,carrefour11);
    listeSegments[16][20] = Segment_init(carrefour16,carrefour20);
    listeSegments[20][16] = Segment_init(carrefour20,carrefour16);

    // Segments horizontaux
    listeSegments[3][4] = Segment_init(carrefour3,carrefour4);
    listeSegments[4][3] = Segment_init(carrefour4,carrefour3);
    listeSegments[4][5] = Segment_init(carrefour4,carrefour5);
    listeSegments[5][4] = Segment_init(carrefour5,carrefour4);
    listeSegments[5][6] = Segment_init(carrefour5,carrefour6);
    listeSegments[6][5] = Segment_init(carrefour6,carrefour5);
    listeSegments[6][7] = Segment_init(carrefour6,carrefour7);
    listeSegments[7][6] = Segment_init(carrefour7,carrefour6);

    listeSegments[8][9] = Segment_init(carrefour8,carrefour9);
    listeSegments[9][8] = Segment_init(carrefour9,carrefour8);
    listeSegments[9][10] = Segment_init(carrefour9,carrefour10);
    listeSegments[10][9] = Segment_init(carrefour10,carrefour9);
    listeSegments[10][11] = Segment_init(carrefour10,carrefour11);
    listeSegments[11][10] = Segment_init(carrefour11,carrefour10);
    listeSegments[11][12] = Segment_init(carrefour11,carrefour12);
    listeSegments[12][11] = Segment_init(carrefour12,carrefour11);

    listeSegments[13][14] = Segment_init(carrefour13,carrefour14);
    listeSegments[14][13] = Segment_init(carrefour14,carrefour13);
    listeSegments[14][15] = Segment_init(carrefour14,carrefour15);
    listeSegments[15][14] = Segment_init(carrefour15,carrefour14);
    listeSegments[15][16] = Segment_init(carrefour15,carrefour16);
    listeSegments[16][15] = Segment_init(carrefour16,carrefour15);
    listeSegments[16][17] = Segment_init(carrefour16,carrefour17);
    listeSegments[17][16] = Segment_init(carrefour17,carrefour16);
printf("here%d\n", 3);
    // Phase 3 : Initialisation des traces possibles
    int tracesL[62][5] = {
        {4},
        {4,5},
        {4,5,6},
        {4,5,6,11},
        {4,5,6,11,16},
        {4,5,10,15},
        {4,5,10,11,16},
        {4,5,10,15,16},
        {4,9},
        {4,9,10,11},
        {4,9,10,11,16},
        {4,9,10,15},
        {4,9,10,15,16},
        {4,9,14},
        {4,9,14,15},
        {4,9,14,15,16},

        {5,4},
        {5,4,9},
        {5,4,9,14},
        {5,6},
        {5,6,11},
        {5,6,11,16},
        {5,10,9},
        {5,10,9,14},
        {5,10,11},
        {5,10,11,16},
        {5,10,15},
        {5,10,15,14},
        {5,10,15,16},

        {6},
        {6,5,4,9},
        {6,5,4,9,14},
        {6,5,10,9},
        {6,5,10,9,14},
        {6,5,10,15},
        {6,5,10,15,14},
        {6,11},
        {6,11,10,9},
        {6,11,10,9,14},
        {6,11,10,15},
        {6,11,10,15,14},
        {6,11,16},
        {6,11,16,15,14},
        {6,11,16,15},

        {9,10,11},
        {9,10,11,16},
        {9,10,15},
        {9,10,15,16},
        {9,14},
        {9,14,15},
        {9,14,15,16},

        {11,10,9,14},
        {11,10,15},
        {11,10,15,14},
        {11,16},
        {11,16,15},
        {11,16,15,14},

        {14},
        {14,5},
        {14,15,16},

        {16},
        {16,15}
    };
printf("here%d\n", 4);
    traces = tracesL;
printf("here%d\n", 5);
    // Phase 4 : Initialisation des chemins possibles
    chemins = (int ***)malloc(20 * sizeof(int **));
    int i, j;
    for(i=0;i<=19;i++)
    {
        chemins[i] = (int **)malloc(20 * sizeof(int *));
        for(j=0;j<=20;j++)
        {
            chemins[i][j] = (int *)malloc(5 * sizeof(int));
        }
    }

    chemins[0][1][0] = 1;
    chemins[0][2][0] = 2;
    chemins[0][3][0] = 0;
    chemins[0][7][0] = chemins[0][2][0];
    chemins[0][8][0] = 8;
    chemins[0][12][0] = 3;
    chemins[0][12][1] = 9;
    chemins[0][13][0] = 13;
    chemins[0][17][0] = 4;
    chemins[0][17][1] = 6;
    chemins[0][17][2] = 7;
    chemins[0][17][3] = 12;
    chemins[0][17][4] = 10;
    chemins[0][17][5] = 15;
    chemins[0][18][0] = chemins[0][13][0];
    chemins[0][19][0] = 5;
    chemins[0][19][1] = 14;
    chemins[0][19][2] = 11;
    chemins[0][20][0] = chemins[0][17][0];
    chemins[0][20][1] = chemins[0][17][1];
    chemins[0][20][2] = chemins[0][17][2];
    chemins[0][20][3] = chemins[0][17][3];
    chemins[0][20][4] = chemins[0][17][4];
    chemins[0][20][5] = chemins[0][17][5];

    chemins[1][2][0] = 19;
    chemins[1][3][0] = 16;
    chemins[1][7][0] = chemins[1][2][0];
    chemins[1][8][0] = 22;
    chemins[1][12][0] = 20;
    chemins[1][12][1] = 24;
    chemins[1][13][0] = 18;
    chemins[1][13][1] = 23;
    chemins[1][13][2] = 27;
    chemins[1][17][0] = 21;
    chemins[1][17][1] = 25;
    chemins[1][17][2] = 28;
    chemins[1][18][0] = chemins[1][13][0];
    chemins[1][18][1] = chemins[1][13][1];
    chemins[1][18][2] = chemins[1][13][2];
    chemins[1][19][0] = 26;
    chemins[1][20][0] = chemins[1][17][0];
    chemins[1][20][1] = chemins[1][17][1];
    chemins[1][20][2] = chemins[1][17][2];

    chemins[2][3][0] = chemins[0][2][0];
    chemins[2][7][0] = 29;
    chemins[2][8][0] = 30;
    chemins[2][8][1] = 22;
    chemins[2][8][2] = 37;
    chemins[2][12][0] = 36;
    chemins[2][13][0] = 31;
    chemins[2][13][1] = 33;
    chemins[2][13][2] = 35;
    chemins[2][13][3] = 38;
    chemins[2][13][4] = 40;
    chemins[2][13][5] = 42;
    chemins[2][17][0] = 41;
    chemins[2][18][0] = chemins[2][13][0];
    chemins[2][18][1] = chemins[2][13][1];
    chemins[2][18][2] = chemins[2][13][2];
    chemins[2][18][3] = chemins[2][13][3];
    chemins[2][18][4] = chemins[2][13][4];
    chemins[2][18][5] = chemins[2][13][5];
    chemins[2][19][0] = 34;
    chemins[2][19][1] = 39;
    chemins[2][19][2] = 43;
    chemins[2][20][0] = chemins[2][17][0];

    chemins[3][7][0] = chemins[0][7][0];
    chemins[3][8][0] = chemins[0][8][0];
    chemins[3][12][0] = chemins[0][12][0];
    chemins[3][12][1] = chemins[0][12][1];
    chemins[3][13][0] = chemins[0][13][0];
    chemins[3][17][0] = chemins[0][17][0];
    chemins[3][17][1] = chemins[0][17][1];
    chemins[3][17][2] = chemins[0][17][2];
    chemins[3][17][3] = chemins[0][17][3];
    chemins[3][17][4] = chemins[0][17][4];
    chemins[3][17][5] = chemins[0][17][5];
    chemins[3][18][0] = chemins[0][18][0];
    chemins[3][19][0] = chemins[0][19][0];
    chemins[3][19][1] = chemins[0][19][1];
    chemins[3][19][2] = chemins[0][19][2];
    chemins[3][20][0] = chemins[0][20][0];
    chemins[3][20][1] = chemins[0][20][1];
    chemins[3][20][2] = chemins[0][20][2];
    chemins[3][20][3] = chemins[0][20][3];
    chemins[3][20][4] = chemins[0][20][4];
    chemins[3][20][5] = chemins[0][20][5];

    chemins[7][8][0] = chemins[2][8][0];
    chemins[7][8][1] = chemins[2][8][1];
    chemins[7][8][2] = chemins[2][8][2];
    chemins[7][12][0] = chemins[2][12][0];
    chemins[7][13][0] = chemins[2][13][0];
    chemins[7][13][1] = chemins[2][13][1];
    chemins[7][13][2] = chemins[2][13][2];
    chemins[7][13][3] = chemins[2][13][3];
    chemins[7][13][4] = chemins[2][13][4];
    chemins[7][13][5] = chemins[2][13][5];
    chemins[7][17][0] = chemins[2][17][0];
    chemins[7][18][0] = chemins[2][18][0];
    chemins[7][18][1] = chemins[2][18][1];
    chemins[7][18][2] = chemins[2][18][2];
    chemins[7][18][3] = chemins[2][18][3];
    chemins[7][18][4] = chemins[2][18][4];
    chemins[7][18][5] = chemins[2][18][5];
    chemins[7][19][0] = chemins[2][19][0];
    chemins[7][19][1] = chemins[2][19][1];
    chemins[7][19][2] = chemins[2][19][2];
    chemins[7][20][0] = chemins[2][20][0];

    chemins[8][12][0] = 44;
    chemins[8][13][0] = 48;
    chemins[8][17][0] = 45;
    chemins[8][17][1] = 47;
    chemins[8][17][2] = 50;
    chemins[8][18][0] = chemins[8][13][0];
    chemins[8][19][0] = 46;
    chemins[8][19][1] = 49;
    chemins[8][20][0] = chemins[8][17][0];
    chemins[8][20][1] = chemins[8][17][1];
    chemins[8][20][2] = chemins[8][17][2];

    chemins[12][13][0] = 51;
    chemins[12][13][1] = 53;
    chemins[12][13][2] = 56;
    chemins[12][17][0] = 54;
    chemins[12][18][0] = chemins[12][13][0];
    chemins[12][18][1] = chemins[12][13][1];
    chemins[12][18][2] = chemins[12][13][2];
    chemins[12][19][0] = 52;
    chemins[12][19][1] = 55;
    chemins[12][20][0] = chemins[12][17][0];

    chemins[13][17][0] = 59;
    chemins[13][18][0] = 57;
    chemins[13][19][0] = 58;
    chemins[13][20][0] = 59;

    chemins[17][18][0] = chemins[13][17][0];
    chemins[17][19][0] = 61;
    chemins[17][20][0] = 60;

    chemins[18][19][0] = chemins[13][18][0];
    chemins[18][20][0] = chemins[13][20][0];

    chemins[19][20][0] = chemins[17][19][0];
printf("here%d\n", 6);*/

}


