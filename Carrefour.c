#include <stdio.h>
#include <stdlib.h>

#include "Carrefour.h"
//#include "Feu.h" >>> pas la peine car Carrefour.h l'inclut déjà


Carrefour * Carrefour_init(int id, int posX, int posY)
{
    Carrefour * carr = NULL;
    carr = (Carrefour *)malloc(sizeof(Carrefour));

    if(carr == NULL)
    {
        printf("Erreur lors de l'initialisation d'un carrefour (id:%d", id);
        exit(0);
    }

    carr->id = id;
    carr->posX = posX;
    carr->posY = posY;

    // Ajouter l'initialisation du tableau de Feux

    return carr;
}


// Détection et correction des erreurs de synchronisation des feux d'un carrefour
void carrefour_detecterErreur(Carrefour carrefour)
{
    if ( (carrefour.tabFeux[0].isVert != carrefour.tabFeux[1].isVert) || (carrefour.tabFeux[2].isVert != carrefour.tabFeux[3].isVert) )
    {
        carrefour.tabFeux[0].isVert = carrefour.tabFeux[1].isVert;
        if ( carrefour.tabFeux[2].isVert == carrefour.tabFeux[0].isVert )
        {
            feu_changerCouleurFeu(carrefour.tabFeux[2]);
            carrefour.tabFeux[3].isVert = carrefour.tabFeux[2].isVert;
        }
    }
}


// Si l'ordonnancement aléatoire est choisi, cette fonction initialise la couleur des feux de manière aléatoire et corrige les erreurs de synchronisation
void carrefour_ordoAlea(listeCarrefours tableauCarrefours)
{
    int j;

        for (j=0; j<4; j++)
        {
            feu_initCouleurFeuAlea(tableauCarrefours[4].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[4]);

            feu_initCouleurFeuAlea(tableauCarrefours[5].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[5]);

            feu_initCouleurFeuAlea(tableauCarrefours[6].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[6]);

            feu_initCouleurFeuAlea(tableauCarrefours[9].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[9]);

            feu_initCouleurFeuAlea(tableauCarrefours[10].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[10]);

            feu_initCouleurFeuAlea(tableauCarrefours[11].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[11]);

            feu_initCouleurFeuAlea(tableauCarrefours[14].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[14]);

            feu_initCouleurFeuAlea(tableauCarrefours[15].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[15]);

            feu_initCouleurFeuAlea(tableauCarrefours[16].tabFeux[j]);
            carrefour_detecterErreur(tableauCarrefours[16]);
        }
}
/*

// Si l'ordonnancement Vague Verte est choisi, cette fonction initialise la couleur des feux de sorte à permettre une vague verte.
// Elle corrige également les erreurs de synchronisation
void carrefour_ordoVagueVerte(Carrefour ** tableauCarrefours)
{
    int i,j,k,l;
    k = 1;

    for (i=0; i<3; i++)
    {
        for (j=k+3; j<k+6; j++)
        {
            //Initialisation des feux de chaque carrefour à rouge
            for (l=0; l<4; l++)
            {
            feu_initCouleurRougeVagueVerte(tableauCarrefours[j]->tabFeux[l]);
            }
            //On place la couleur d'un feu à vert et la détection s'occupe d'initialiser les autres
            tableauCarrefours[j]->tabFeux[0]->isVert = 1;
            carrefour_detecterErreur(tableauCarrefours[j]);
        }
        k = k+5;
    }
}
*/
