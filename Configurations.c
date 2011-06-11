/**
 * \file Configurations.c
 * \brief Configurations et initialisations
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 */

#include "Configurations.h"

/**
 * \fn void init_listeCarrefours(ListeCarrefours listeCarrefours, int padding, int espaceRoutes, int largeurRoutes)
 * \brief Initialise la liste des Carrefours pour la suite du programme
 *
 * \param listeCarrefours Un tableau ListeCarrefours, déjà allouée
 * \param padding Distance du quartier par rapport aux bords de la fenêtre
 * \param espaceRoutes Espace entre les routes du quartier
 * \param largeurRoutes Largeur des routes du quartier
 */
void init_listeCarrefours(ListeCarrefours listeCarrefours, int padding, int espaceRoutes, int largeurRoutes)
{
    // Phase 1 : Initialisation des carrefours
    Carrefour * carrefour0 = Carrefour_init(0, padding + espaceRoutes, 0);
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

    listeCarrefours[0] = carrefour0;
    listeCarrefours[1] = carrefour1;
    listeCarrefours[2] = carrefour2;
    listeCarrefours[3] = carrefour3;
    listeCarrefours[4] = carrefour4;
    listeCarrefours[5] = carrefour5;
    listeCarrefours[6] = carrefour6;
    listeCarrefours[7] = carrefour7;
    listeCarrefours[8] = carrefour8;
    listeCarrefours[9] = carrefour9;
    listeCarrefours[10] = carrefour10;
    listeCarrefours[11] = carrefour11;
    listeCarrefours[12] = carrefour12;
    listeCarrefours[13] = carrefour13;
    listeCarrefours[14] = carrefour14;
    listeCarrefours[15] = carrefour15;
    listeCarrefours[16] = carrefour16;
    listeCarrefours[17] = carrefour17;
    listeCarrefours[18] = carrefour18;
    listeCarrefours[19] = carrefour19;
    listeCarrefours[20] = carrefour20;
}

/**
 * \fn void destroy_listeCarrefours(ListeCarrefours listeCarrefours)
 * \brief Détruit les Carrefours contenus dans un tableau ListeCarrefours
 *
 * \param listeCarrefours Un tableau de type ListeCarrefour contenant les Carrefours à désalouer
 */
void destroy_listeCarrefours(ListeCarrefours listeCarrefours)
{
    int i;
    for(i=0;i<=20;i++)
    {
        Carrefour_destroy(listeCarrefours[i]);
    }
}

/**
 * \fn void init_listeSegments(ListeSegments listeSegments, ListeCarrefours listeCarrefours)
 * \brief Initialise la liste des Segments
 *
 * \param listeSegments Un tableau ListeSegments, déjà alloué
 * \param listeCarrefours Un tableau ListeCarrefours, déjà initialisé
 */
void init_listeSegments(ListeSegments listeSegments, ListeCarrefours listeCarrefours)
{
    listeSegments[0][4] = Segment_init(listeCarrefours[0],listeCarrefours[4]);
    listeSegments[4][0] = Segment_init(listeCarrefours[4],listeCarrefours[0]);
    listeSegments[4][9] = Segment_init(listeCarrefours[4],listeCarrefours[9]);
    listeSegments[9][4] = Segment_init(listeCarrefours[9],listeCarrefours[4]);
    listeSegments[9][14] = Segment_init(listeCarrefours[9],listeCarrefours[14]);
    listeSegments[14][9] = Segment_init(listeCarrefours[14],listeCarrefours[9]);
    listeSegments[14][18] = Segment_init(listeCarrefours[14],listeCarrefours[18]);
    listeSegments[18][14] = Segment_init(listeCarrefours[18],listeCarrefours[14]);

    listeSegments[1][5] = Segment_init(listeCarrefours[1],listeCarrefours[5]);
    listeSegments[5][1] = Segment_init(listeCarrefours[5],listeCarrefours[1]);
    listeSegments[5][10] = Segment_init(listeCarrefours[5],listeCarrefours[10]);
    listeSegments[10][5] = Segment_init(listeCarrefours[10],listeCarrefours[5]);
    listeSegments[10][15] = Segment_init(listeCarrefours[10],listeCarrefours[15]);
    listeSegments[15][10] = Segment_init(listeCarrefours[15],listeCarrefours[10]);
    listeSegments[15][19] = Segment_init(listeCarrefours[15],listeCarrefours[19]);
    listeSegments[19][15] = Segment_init(listeCarrefours[19],listeCarrefours[15]);

    listeSegments[2][6] = Segment_init(listeCarrefours[12],listeCarrefours[6]);
    listeSegments[6][2] = Segment_init(listeCarrefours[6],listeCarrefours[12]);
    listeSegments[6][11] = Segment_init(listeCarrefours[6],listeCarrefours[11]);
    listeSegments[11][6] = Segment_init(listeCarrefours[11],listeCarrefours[6]);
    listeSegments[11][16] = Segment_init(listeCarrefours[11],listeCarrefours[16]);
    listeSegments[16][11] = Segment_init(listeCarrefours[16],listeCarrefours[11]);
    listeSegments[16][20] = Segment_init(listeCarrefours[16],listeCarrefours[20]);
    listeSegments[20][16] = Segment_init(listeCarrefours[20],listeCarrefours[16]);

    // Segments horizontaux
    listeSegments[3][4] = Segment_init(listeCarrefours[3],listeCarrefours[4]);
    listeSegments[4][3] = Segment_init(listeCarrefours[4],listeCarrefours[3]);
    listeSegments[4][5] = Segment_init(listeCarrefours[4],listeCarrefours[5]);
    listeSegments[5][4] = Segment_init(listeCarrefours[5],listeCarrefours[4]);
    listeSegments[5][6] = Segment_init(listeCarrefours[5],listeCarrefours[6]);
    listeSegments[6][5] = Segment_init(listeCarrefours[6],listeCarrefours[5]);
    listeSegments[6][7] = Segment_init(listeCarrefours[6],listeCarrefours[7]);
    listeSegments[7][6] = Segment_init(listeCarrefours[7],listeCarrefours[6]);

    listeSegments[8][9] = Segment_init(listeCarrefours[8],listeCarrefours[9]);
    listeSegments[9][8] = Segment_init(listeCarrefours[9],listeCarrefours[8]);
    listeSegments[9][10] = Segment_init(listeCarrefours[9],listeCarrefours[10]);
    listeSegments[10][9] = Segment_init(listeCarrefours[10],listeCarrefours[9]);
    listeSegments[10][11] = Segment_init(listeCarrefours[10],listeCarrefours[11]);
    listeSegments[11][10] = Segment_init(listeCarrefours[11],listeCarrefours[10]);
    listeSegments[11][12] = Segment_init(listeCarrefours[11],listeCarrefours[12]);
    listeSegments[12][11] = Segment_init(listeCarrefours[12],listeCarrefours[11]);

    listeSegments[13][14] = Segment_init(listeCarrefours[13],listeCarrefours[14]);
    listeSegments[14][13] = Segment_init(listeCarrefours[14],listeCarrefours[13]);
    listeSegments[14][15] = Segment_init(listeCarrefours[14],listeCarrefours[15]);
    listeSegments[15][14] = Segment_init(listeCarrefours[15],listeCarrefours[14]);
    listeSegments[15][16] = Segment_init(listeCarrefours[15],listeCarrefours[16]);
    listeSegments[16][15] = Segment_init(listeCarrefours[16],listeCarrefours[15]);
    listeSegments[16][17] = Segment_init(listeCarrefours[16],listeCarrefours[17]);
    listeSegments[17][16] = Segment_init(listeCarrefours[17],listeCarrefours[16]);
}

/**
 * \fn void destroy_listeSegments(ListeSegments listeSegments)
 * \brief Détruit les Segments contenus dans le tableau ListeCarrefours. Elle dépend des traitements effectués dans la fonction init_listeCarrefours()
 *
 * \param listeSegments Un tableau de type ListeSegments contenant les Segments à désalouer
 */
void destroy_listeSegments(ListeSegments listeSegments)
{
    Segment_destroy(listeSegments[0][4]);
    Segment_destroy(listeSegments[4][0]);
    Segment_destroy(listeSegments[4][9]);
    Segment_destroy(listeSegments[9][4]);
    Segment_destroy(listeSegments[9][14]);
    Segment_destroy(listeSegments[14][9]);
    Segment_destroy(listeSegments[14][18]);
    Segment_destroy(listeSegments[18][14]);

    Segment_destroy(listeSegments[1][5]);
    Segment_destroy(listeSegments[5][1]);
    Segment_destroy(listeSegments[5][10]);
    Segment_destroy(listeSegments[10][5]);
    Segment_destroy(listeSegments[10][15]);
    Segment_destroy(listeSegments[15][10]);
    Segment_destroy(listeSegments[15][19]);
    Segment_destroy(listeSegments[19][15]);

    Segment_destroy(listeSegments[2][6]);
    Segment_destroy(listeSegments[6][2]);
    Segment_destroy(listeSegments[6][11]);
    Segment_destroy(listeSegments[11][6]);
    Segment_destroy(listeSegments[11][16]);
    Segment_destroy(listeSegments[16][11]);
    Segment_destroy(listeSegments[16][20]);
    Segment_destroy(listeSegments[20][16]);

    // Segments horizontaux
    Segment_destroy(listeSegments[3][4]);
    Segment_destroy(listeSegments[4][3]);
    Segment_destroy(listeSegments[4][5]);
    Segment_destroy(listeSegments[5][4]);
    Segment_destroy(listeSegments[5][6]);
    Segment_destroy(listeSegments[6][5]);
    Segment_destroy(listeSegments[6][7]);
    Segment_destroy(listeSegments[7][6]);

    Segment_destroy(listeSegments[8][9]);
    Segment_destroy(listeSegments[9][8]);
    Segment_destroy(listeSegments[9][10]);
    Segment_destroy(listeSegments[10][9]);
    Segment_destroy(listeSegments[10][11]);
    Segment_destroy(listeSegments[11][10]);
    Segment_destroy(listeSegments[11][12]);
    Segment_destroy(listeSegments[12][11]);

    Segment_destroy(listeSegments[13][14]);
    Segment_destroy(listeSegments[14][13]);
    Segment_destroy(listeSegments[14][15]);
    Segment_destroy(listeSegments[15][14]);
    Segment_destroy(listeSegments[15][16]);
    Segment_destroy(listeSegments[16][15]);
    Segment_destroy(listeSegments[16][17]);
    Segment_destroy(listeSegments[17][16]);

}


/**
 * \fn void init_traces(Traces traces)
 * \brief Initialise la liste des tracés avec les tracés possibles dans le quartier
 *
 * \param traces Un tableau de type Traces
 */
void init_traces(Traces traces)
{
    // La première case de chaque tableau a pour valeur la taille du tableau
    // Pour permettre la fonction Voiture_inverserTableau()

    // Phase 3 : Initialisation des traces possibles
    int tracesL[62][8] = {
        // 4
        {1,4,-1,-1,-1,-1,-1},
        {1,4,5,-1,-1,-1,-1},
        {1,4,5,6,-1,-1,-1},
        {-1,4,5,6,11,-1,-1},
        {-1,4,5,6,11,16,-1},
        {-1,4,5,10,15,-1,-1},
        {-1,4,5,10,11,16,-1},
        {-1,4,5,10,15,16,-1},
        {-1,4,9,-1,-1,-1,-1},
        {-1,4,9,10,11,-1,-1},
        {-1,4,9,10,11,16,-1},
        {-1,4,9,10,15,-1,-1},
        {-1,4,9,10,15,16,-1},
        {-1,4,9,14,-1,-1,-1},
        {-1,4,9,14,15,-1,-1},
        {-1,4,9,14,15,16,-1},

        // 5
        {-1,5,4,-1,-1,-1,-1},
        {-1,5,4,9,-1,-1,-1},
        {-1,5,4,9,14,-1,-1},
        {-1,5,6,-1,-1,-1,-1},
        {-1,5,6,11,-1,-1,-1},
        {-1,5,6,11,16,-1,-1},
        {-1,5,10,9,-1,-1,-1},
        {-1,5,10,9,14,-1,-1},
        {-1,5,10,11,-1,-1,-1},
        {-1,5,10,11,16,-1,-1},
        {-1,5,10,15,-1,-1,-1},
        {-1,5,10,15,14,-1,-1},
        {-1,5,10,15,16,-1,-1},

        // 6
        {-1,6,-1,-1,-1,-1,-1},
        {-1,6,5,4,9,-1,-1},
        {-1,6,5,4,9,14,-1},
        {-1,6,5,10,9,-1,-1},
        {-1,6,5,10,9,14,-1},
        {-1,6,5,10,15,-1,-1},
        {-1,6,5,10,15,14,-1},
        {-1,6,11,-1,-1,-1,-1},
        {-1,6,11,10,9,-1,-1},
        {-1,6,11,10,9,14,-1},
        {-1,6,11,10,15,-1,-1},
        {-1,6,11,10,15,14,-1},
        {-1,6,11,16,-1,-1,-1},
        {-1,6,11,16,15,14,-1},
        {-1,6,11,16,15,-1,-1},

        // 9
        {-1,9,10,11,-1,-1,-1},
        {-1,9,10,11,16,-1,-1},
        {-1,9,10,15,-1,-1,-1},
        {-1,9,10,15,16,-1,-1},
        {-1,9,14,-1,-1,-1,-1},
        {-1,9,14,15,-1,-1,-1},
        {-1,9,14,15,16,-1,-1},

        // 11
        {-1,11,10,9,14,-1,-1},
        {-1,11,10,15,-1,-1,-1},
        {-1,11,10,15,14,-1,-1},
        {-1,11,16,-1,-1,-1,-1},
        {-1,11,16,15,-1,-1,-1},
        {-1,11,16,15,14,-1,-1},

        // 14
        {-1,14,-1,-1,-1,-1,-1},
        {-1,14,5,-1,-1,-1,-1},
        {-1,14,15,16,-1,-1,-1},

        // 16
        {-1,16,-1,-1,-1,-1,-1},
        {-1,16,15,-1,-1,-1,-1}
    };

    int i,j;
    for(i=0;i<=61;i++)
    {
        for(j=0;j<=7;j++)
        {
            traces[i][j] = tracesL[i][j];
        }
    }
}

/**
 * \fn void init_chemins(Chemins chemins)
 * \brief Initialise la liste des chemins avec les chemins possibles entre les Carrefours
 *
 * \param traces Un tableau de type Chemins
 */
void init_chemins(Chemins chemins)
{
    chemins[0][1][0] = 1;
    chemins[0][1][1] = 1;

    chemins[0][2][0] = 1;
    chemins[0][2][1] = 2;

    chemins[0][3][0] = 1;
    chemins[0][3][1] = 0;

    chemins[0][7][0] = 1;
    chemins[0][7][1] = chemins[0][2][1];

    chemins[0][8][0] = 1;
    chemins[0][8][1] = 8;

    chemins[0][12][0] = 2;
    chemins[0][12][1] = 3;
    chemins[0][12][2] = 9;

    chemins[0][13][0] = 1;
    chemins[0][13][1] = 13;

    chemins[0][17][0] = 6;
    chemins[0][17][1] = 4;
    chemins[0][17][2] = 6;
    chemins[0][17][3] = 7;
    chemins[0][17][4] = 12;
    chemins[0][17][5] = 10;
    chemins[0][17][6] = 15;

    chemins[0][18][0] = 1;
    chemins[0][18][1] = chemins[0][13][1];

    chemins[0][19][0] = 3;
    chemins[0][19][1] = 5;
    chemins[0][19][2] = 14;
    chemins[0][19][3] = 11;

    chemins[0][20][0] = 6;
    chemins[0][20][1] = chemins[0][17][1];
    chemins[0][20][2] = chemins[0][17][2];
    chemins[0][20][3] = chemins[0][17][3];
    chemins[0][20][4] = chemins[0][17][4];
    chemins[0][20][5] = chemins[0][17][5];
    chemins[0][20][6] = chemins[0][17][6];


    chemins[1][2][0] = 1;
    chemins[1][2][1] = 19;

    chemins[1][3][0] = 1;
    chemins[1][3][1] = 16;

    chemins[1][7][0] = 1;
    chemins[1][7][1] = chemins[1][2][1];

    chemins[1][8][0] = 1;
    chemins[1][8][1] = 22;

    chemins[1][12][0] = 2;
    chemins[1][12][1] = 20;
    chemins[1][12][2] = 24;

    chemins[1][13][0] = 3;
    chemins[1][13][1] = 18;
    chemins[1][13][2] = 23;
    chemins[1][13][3] = 27;

    chemins[1][17][0] = 3;
    chemins[1][17][1] = 21;
    chemins[1][17][2] = 25;
    chemins[1][17][3] = 28;

    chemins[1][18][0] = 3;
    chemins[1][18][1] = chemins[1][13][1];
    chemins[1][18][2] = chemins[1][13][2];
    chemins[1][18][3] = chemins[1][13][3];

    chemins[1][19][0] = 1;
    chemins[1][19][1] = 26;

    chemins[1][20][0] = 3;
    chemins[1][20][1] = chemins[1][17][1];
    chemins[1][20][2] = chemins[1][17][2];
    chemins[1][20][3] = chemins[1][17][3];


    chemins[2][3][0] = 1;
    chemins[2][3][1] = chemins[0][2][1];

    chemins[2][7][0] = 1;
    chemins[2][7][1] = 29;

    chemins[2][8][0] = 3;
    chemins[2][8][1] = 30;
    chemins[2][8][2] = 22;
    chemins[2][8][3] = 37;

    chemins[2][12][0] = 1;
    chemins[2][12][1] = 36;

    chemins[2][13][0] = 6;
    chemins[2][13][1] = 31;
    chemins[2][13][2] = 33;
    chemins[2][13][3] = 35;
    chemins[2][13][4] = 38;
    chemins[2][13][5] = 40;
    chemins[2][13][6] = 42;

    chemins[2][17][0] = 1;
    chemins[2][17][1] = 41;

    chemins[2][18][0] = 6;
    chemins[2][18][1] = chemins[2][13][1];
    chemins[2][18][2] = chemins[2][13][2];
    chemins[2][18][3] = chemins[2][13][3];
    chemins[2][18][4] = chemins[2][13][4];
    chemins[2][18][5] = chemins[2][13][5];
    chemins[2][18][6] = chemins[2][13][6];

    chemins[2][19][0] = 3;
    chemins[2][19][1] = 34;
    chemins[2][19][2] = 39;
    chemins[2][19][3] = 43;

    chemins[2][20][0] = 1;
    chemins[2][20][1] = chemins[2][17][1];


    chemins[3][7][0] = 1;
    chemins[3][7][1] = chemins[0][7][1];

    chemins[3][8][0] = 1;
    chemins[3][8][1] = chemins[0][8][1];

    chemins[3][12][0] = 2;
    chemins[3][12][1] = chemins[0][12][1];
    chemins[3][12][2] = chemins[0][12][2];

    chemins[3][13][0] = 1;
    chemins[3][13][1] = chemins[0][13][1];

    chemins[3][17][0] = 1;
    chemins[3][17][1] = chemins[0][17][1];
    chemins[3][17][2] = chemins[0][17][2];
    chemins[3][17][3] = chemins[0][17][3];
    chemins[3][17][4] = chemins[0][17][4];
    chemins[3][17][5] = chemins[0][17][5];
    chemins[3][17][6] = chemins[0][17][6];

    chemins[3][18][0] = 1;
    chemins[3][18][1] = chemins[0][18][1];

    chemins[3][19][0] = 3;
    chemins[3][19][1] = chemins[0][19][1];
    chemins[3][19][2] = chemins[0][19][2];
    chemins[3][19][3] = chemins[0][19][3];

    chemins[3][20][0] = 6;
    chemins[3][20][1] = chemins[0][20][1];
    chemins[3][20][2] = chemins[0][20][2];
    chemins[3][20][3] = chemins[0][20][3];
    chemins[3][20][4] = chemins[0][20][4];
    chemins[3][20][5] = chemins[0][20][5];
    chemins[3][20][6] = chemins[0][20][6];


    chemins[7][8][0] = 3;
    chemins[7][8][1] = chemins[2][8][1];
    chemins[7][8][2] = chemins[2][8][2];
    chemins[7][8][3] = chemins[2][8][3];

    chemins[7][12][0] = 1;
    chemins[7][12][1] = chemins[2][12][0];

    chemins[7][13][0] = 6;
    chemins[7][13][1] = chemins[2][13][1];
    chemins[7][13][2] = chemins[2][13][2];
    chemins[7][13][3] = chemins[2][13][3];
    chemins[7][13][4] = chemins[2][13][4];
    chemins[7][13][5] = chemins[2][13][5];
    chemins[7][13][6] = chemins[2][13][6];

    chemins[7][17][0] = 1;
    chemins[7][17][1] = chemins[2][17][1];

    chemins[7][18][0] = 6;
    chemins[7][18][1] = chemins[2][18][1];
    chemins[7][18][2] = chemins[2][18][2];
    chemins[7][18][3] = chemins[2][18][3];
    chemins[7][18][4] = chemins[2][18][4];
    chemins[7][18][5] = chemins[2][18][5];
    chemins[7][18][6] = chemins[2][18][6];

    chemins[7][19][0] = 3;
    chemins[7][19][1] = chemins[2][19][1];
    chemins[7][19][2] = chemins[2][19][2];
    chemins[7][19][3] = chemins[2][19][3];

    chemins[7][20][0] = 1;
    chemins[7][20][1] = chemins[2][20][1];


    chemins[8][12][0] = 1;
    chemins[8][12][1] = 44;

    chemins[8][13][0] = 1;
    chemins[8][13][1] = 48;

    chemins[8][17][0] = 3;
    chemins[8][17][1] = 45;
    chemins[8][17][2] = 47;
    chemins[8][17][3] = 50;

    chemins[8][18][0] = 1;
    chemins[8][18][1] = chemins[8][13][1];

    chemins[8][19][0] = 1;
    chemins[8][19][1] = 46;
    chemins[8][19][2] = 49;

    chemins[8][20][0] = 3;
    chemins[8][20][1] = chemins[8][17][1];
    chemins[8][20][2] = chemins[8][17][2];
    chemins[8][20][3] = chemins[8][17][3];


    chemins[12][13][0] = 3;
    chemins[12][13][1] = 51;
    chemins[12][13][2] = 53;
    chemins[12][13][3] = 56;

    chemins[12][17][0] = 1;
    chemins[12][17][1] = 54;

    chemins[12][18][0] = 3;
    chemins[12][18][1] = chemins[12][13][1];
    chemins[12][18][2] = chemins[12][13][2];
    chemins[12][18][3] = chemins[12][13][3];

    chemins[12][19][0] = 2;
    chemins[12][19][1] = 52;
    chemins[12][19][2] = 55;

    chemins[12][20][0] = 1;
    chemins[12][20][1] = chemins[12][17][1];


    chemins[13][17][0] = 1;
    chemins[13][17][1] = 59;

    chemins[13][18][0] = 1;
    chemins[13][18][1] = 57;

    chemins[13][19][0] = 1;
    chemins[13][19][1] = 58;

    chemins[13][20][0] = 1;
    chemins[13][20][1] = 59;

    chemins[17][18][0] = 1;
    chemins[17][18][1] = chemins[13][17][1];

    chemins[17][19][0] = 1;
    chemins[17][19][1] = 61;

    chemins[17][20][0] = 1;
    chemins[17][20][1] = 60;


    chemins[18][19][0] = 1;
    chemins[18][19][1] = chemins[13][18][1];

    chemins[18][20][0] = 1;
    chemins[18][20][1] = chemins[13][20][1];


    chemins[19][20][0] = 1;
    chemins[19][20][1] = chemins[17][19][1];
}
