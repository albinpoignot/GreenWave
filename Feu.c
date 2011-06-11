/**
 * \file Feu.c
 * \brief Module Feu
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 */

#include <stdio.h>
#include <stdlib.h>

#include "Feu.h"



/**
 * \fn Feu * Feu_create(void)
 * \brief Alloue une structure Feu sur le tas et retourne un pointeur sur cette structure
 *
 * \return Pointeur sur la structure Feu nouvellement allouée
 */
Feu * Feu_create(void)
{
    Feu * feu;
    feu = malloc(sizeof(Feu));

    if ( feu == NULL )
    {
         fprintf(stderr,"Echec de l'allocation");
         exit(EXIT_FAILURE);
    }

    return feu;
}

/**
 * \fn void Feu_destroy(Feu * feu)
 * \brief Détruit une structure Feu précédemment allouée
 *
 * \param feu Pointeur sur la structure à libérer
 */
void Feu_destroy(Feu * feu)
{
    free(feu);
}

/**
 * \fn void Feu_initCouleurFeuAlea(Feu feu)
 * \brief Initialise aléatoirement la couleur du feu
 *
 * \param feu Structure Feu dont la couleur doit être initialisée
 */
void Feu_initCouleurFeuAlea(Feu feu)
{
    feu.isVert = rand()%1;
}

/**
 * \fn void Feu_initCouleurRougeVagueVerte(Feu feu)
 * \brief Initialise la couleur d'une structure Feu à rouge
 *
 * \param feu Structure Feu dont la couleur doit être initialisée
 */
void Feu_initCouleurRougeVagueVerte(Feu feu)
{
    feu.isVert = 0;
}

/**
 * \fn void Feu_changerCouleurFeu(Feu feu)
 * \brief Change la couleur d'une structure Feu
 *
 * \param feu Structure Feu dont la couleur doit être changée
 */
void Feu_changerCouleurFeu(Feu feu)
{
	if (feu.isVert == 1)
	{
		feu.isVert = 0;
	}
	else
	{
	    feu.isVert = 1;
	}
}

/**
 * \fn void Feu_changerCouleurFinTempo(Feu feu)
 * \brief Change la couleur d'une structure Feu lorsque la temporisation choisie dans la structure a été effectuée
 *
 * \param feu Structure Feu dont la couleur doit être changée
 */
void Feu_changerCouleurFinTempo(Feu feu)
{
    if (feu.tempoCourant == feu.tempo)
    {
      feu.tempoCourant = 0;
      Feu_changerCouleurFeu(feu);
    }
}
