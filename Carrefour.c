/**
 * \file Carrefour.c
 * \brief Module Carrefour
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 */

#include <stdio.h>
#include <stdlib.h>

#include "Carrefour.h"

/**
 * \fn Carrefour * Carrefour_init(int id, int posX, int posY)
 * \brief Alloue sur le tas une structure Carrefour et initialise les éléments
 *
 * \param id Identifiant de la voiture
 * \param posX Position sur l'axe X (origine en haut à gauche de la fenêtre)
 * \param posY Position sur l'axe Y (origine en haut à gauche de la fenêtre)
 *
 * \return La structure Carrefour nouvellement allouée, prête à être dessinée
 */
Carrefour * Carrefour_init(int id, int posX, int posY)
{
    Carrefour * carr = NULL;
    carr = (Carrefour *)malloc(sizeof(Carrefour));

    if(carr == NULL)
    {
        printf("Erreur lors de l'initialisation d'un carrefour (id:%d)", id);
        exit(0);
    }

    carr->id = id;
    carr->posX = posX;
    carr->posY = posY;

    // Ajouter l'initialisation du tableau de Feux

    return carr;
}

/**
 * \fn void Carrefour_destroy(Carrefour * carr)
 * \brief Libère la mémoire occupée par une structure Carrefour
 *
 * \param carr Le carrefour à libérer
 */
void Carrefour_destroy(Carrefour * carr)
{
    free(carr);
}


/**
 * \fn void carrefour_detecterErreur(Carrefour carrefour)
 * \brief Détecte une erreur dans la configuration des feux d'un Carrefour
 *
 * \param Carrefour Le carrefour dont les feux doivent être testés
 */
void Carrefour_detecterErreur(Carrefour carrefour)
{
    if ( (carrefour.tabFeux[0].isVert != carrefour.tabFeux[1].isVert) || (carrefour.tabFeux[2].isVert != carrefour.tabFeux[3].isVert) )
    {
        carrefour.tabFeux[0].isVert = carrefour.tabFeux[1].isVert;
        if ( carrefour.tabFeux[2].isVert == carrefour.tabFeux[0].isVert )
        {
            Feu_changerCouleurFeu(carrefour.tabFeux[2]);
            carrefour.tabFeux[3].isVert = carrefour.tabFeux[2].isVert;
        }
    }
}

/**
 * \fn void Carrefour_ordoAlea(ListeCarrefours tableauCarrefours)
 * \brief Initialise la couleur des feux de manière aléatoire et corrige les erreurs de synchronisation
 *
 * \param tableauCarrefours Liste des Carrefours du quartier
 */
void Carrefour_ordoAlea(ListeCarrefours tableauCarrefours)
{
    /*int j;

    for (j=0; j<4; j++)
    {
        Feu_initCouleurFeuAlea(tableauCarrefours[4].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[4]);

        Feu_initCouleurFeuAlea(tableauCarrefours[5].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[5]);

        Feu_initCouleurFeuAlea(tableauCarrefours[6].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[6]);

        Feu_initCouleurFeuAlea(tableauCarrefours[9].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[9]);

        Feu_initCouleurFeuAlea(tableauCarrefours[10].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[10]);

        Feu_initCouleurFeuAlea(tableauCarrefours[11].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[11]);

        Feu_initCouleurFeuAlea(tableauCarrefours[14].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[14]);

        Feu_initCouleurFeuAlea(tableauCarrefours[15].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[15]);

        Feu_initCouleurFeuAlea(tableauCarrefours[16].tabFeux[j]);
        Carrefour_detecterErreur(tableauCarrefours[16]);
    }*/
}


/**
 * \fn void Carrefour_ordoVagueVerte(Carrefour ** tableauCarrefours)
 * \brief Initialise la couleur des feux de sorte à permettre une vague verte et corrige éventuellement les erreurs de synchronisation
 *
 * \param tableauCarrefours Liste des Carrefours du quartier
 */
void Carrefour_ordoVagueVerte(ListeCarrefours tableauCarrefours)
{
    /*int i,j,k,l;
    k = 1;

    for (i=0; i<3; i++)
    {
        for (j=k+3; j<k+6; j++)
        {
            //Initialisation des feux de chaque carrefour à rouge
            for (l=0; l<4; l++)
            {
                Feu_initCouleurRougeVagueVerte(tableauCarrefours[j]->tabFeux[l]);
            }
            //On place la couleur d'un feu à vert et la détection s'occupe d'initialiser les autres
            tableauCarrefours[j]->tabFeux[0]->isVert = 1;
            Carrefour_detecterErreur(tableauCarrefours[j]);
        }
        k = k+5;
    }*/
}

