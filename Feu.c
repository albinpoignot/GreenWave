#include <stdio.h>
#include <stdlib.h>

#include "Feu.h"

// Ce module est totalement indépendant des autres : un feu peut fonctionner seul.


// Allocation des ressources nécesssaires à création d'un objet Feu
Feu * feu_create(void)
{
    Feu * feu;
    feu = malloc(sizeof(Feu));

    if ( feu == NULL )
    {
         fprintf(stderr,"Echec de l'allocation");
         exit(EXIT_FAILURE);
    }
}

// Libération de l'espace mémoire réservé pour un objet Feu, lorsqu'il devient inutile
void feu_destroy(Feu feu)
{
//on n'a pas besoin de désallouer des entiers car ils ne sont pas alloués à l'origine : on leur affecte juste une valeur à l'initialisation
}

// Initialisation aléatoire de la couleur d'un feu
// Ici, aucune synchronisation n'est faite pour éviter les collisions à un carrefour
void feu_initCouleurFeuAlea(Feu feu)
{
    feu.isVert = rand()%1;
}

// Initialisation de la couleur de tous les feux à rouge
void feu_initCouleurRougeVagueVerte(Feu feu)
{
    feu.isVert = 0;
}

// Changement de la couleur d'un feu
void feu_changerCouleurFeu(Feu feu)
{
	if (feu.isVert == 1)
	{
		feu.isVert = 0;
	}
	else
		feu.isVert = 1;
}

// Temporisation : durée pendant laquelle un feu reste dans le même état (rouge, vert)
void feu_temporisation (Feu feu)
{
	int i;

	for(i=0; i<feu.tempo; i++)
	{

	}
}

// Changement de la couleur d'un feu à la fin de la temporisation
void feu_changerCouleurFinTempo(Feu feu)
{
    feu_temporisation(feu);
	feu_changerCouleurFeu(feu);
	feu_changerCouleurFinTempo(feu);
}
