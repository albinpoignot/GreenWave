#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Voiture.h"

#define VITESSE_MAX 30

// Initialisation et destruction d'une voiture
/**
 * \fn Voiture * Voiture_create()
 * \brief Alloue une correctement une structure Voiture et la retourne
 *
 * \return La structure Voiture nouvellement allouée
 */
Voiture * Voiture_create()
{
    Voiture * voit = NULL;

    voit = (Voiture *)malloc(sizeof(Voiture));

    return voit;
}

/**
 * \fn void Voiture_destroy(Voiture *voiture);
 * \brief Libère la mémoire utilisée par la structure Voiture en paramêtre
 *
 * \param voiture La voiture à libérer
 */
void Voiture_destroy(Voiture *voiture)
{
    free(voiture);
}

/**
 * \fn void Voiture_deplacer(Voiture *voiture);
 * \brief Définit la file de la voiture, la mets dedans et lance le déplacement sur le segment
 *          [ traceChoisi[1], [traceChoisi[2] ]
 *
 * \param voiture La voiture à déplacer
 */
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr)
{
    // Phase 1 : définition des indices des carrefours
    int indiceCarrSource = voiture->traceChoisi[0];
    int indiceCarrDest = Voiture_definirIndiceCarrefourDest(voiture->traceChoisi[0], voiture->traceChoisi[1]);

    // Phase 2 : définition de la file de la voiture
    voiture->fileActuelle = listeSeg[indiceCarrSource][indiceCarrDest]->file;

    // Phase 3 : lancement du déplacement
    Voiture_bouger(voiture, listeCarr);
}

/**
 * \fn void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant)
 * \brief Déplacement de la voiture sur un axe horizontal. Gère l'accélération et la
 *          décélération en cas de besoin.
 *
 * \param voiture La voiture à déplacer
 * \param voitureDevant La voiture se trouvant devant la voiture à déplacer
 */
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
{

    // ----- Phase 1 : Définition des diverses distances
    int distanceArret = voiture->vitesseInstantanee * 2; // Distance d'arret = v * 2 secondes
    distanceArret = pow(distanceArret, 2); // Pour simplification des calculs futurs

    // Calcul de la distance actuelle entre les deux voitures
    int distanceEntreVoitures = pow(voiture->posX - voitureDevant->posX, 2) + pow(voiture->posY - voitureDevant->posY, 2);

    // ----- Phase 2 : déplacement jusqu'au bout du segment
    // Si la distance est suffisante et que la voiture n'est pas trop proche du carrefour
    Carrefour carr = listeCarr[voiture->traceChoisi[1]];
    while(distanceEntreVoitures > distanceArret && (voiture->posX != (carr.posX - distanceArret)) )
    {
        // ** Phase 2.1 : Accélération éventuelle et calcul de la nouvelle distance d'arret
        if(voiture->vitesseInstantanee < VITESSE_MAX)
        {
            voiture->vitesseInstantanee += 1;
            distanceArret = pow(voiture->vitesseInstantanee * 2,2);
        }

        // ** Phase 2.2 : Déplacement
        voiture->posX += voiture->vitesseInstantanee;
    }

    // ----- Phase 3 : Arrêt du véhicule
    // En cas de feu rouge ou de voiture à l'arrêt devant, on ralentit jusqu'à l'arrêt
printf("Voiture.c, fct deplacementHorizontal(), phase 3, implémenter les feux rouges\n");
    if(distanceEntreVoitures <= distanceArret)
    {
        while(voiture->vitesseInstantanee > 0)
        {
            voiture->vitesseInstantanee -= 1;
            voiture->posX += voiture->vitesseInstantanee;
        }
    }
    else
    {
        // Sinon, on change les donnees de traceChoisi, on met à jour les files et on recommence
        // un déplacement
        int i;
        int arrayLength = sizeof(voiture->traceChoisi) / sizeof(int);

        // ** Phase 3.1 : Mise à jour de traceChoisi
        for(i=0; i<=arrayLength; i++)
        {
            if(voiture->traceChoisi[i] != NULL && voiture->traceChoisi[i+1] != NULL)
            {
                voiture->traceChoisi[i] = voiture->traceChoisi[i+1];
            }
            else
            {
                i = arrayLength; // On arrête si le reste du tableau est vide
            }
        }

        // ** Phase 3.2 : Mise à jour des files et relancement du déplacement
printf("Voiture.c, fct deplacementHorizontal(), phase 3.2, défiler la voiture");

        if(voiture->traceChoisi[2] != NULL)
        {
            ListeSegments listeSeg;
            Voiture_deplacer(voiture, listeSeg, listeCarr);
        }
    }


}


void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant)
{

}


/**
 * \fn void Voiture_bouger(Voiture *voiture)
 * \brief Cette fonction boucle sur elle-même tant que la voiture n'a pas la possibilité d'avancer
 *          (i.e la voiture de devant est trop proche)
 *
 * \param voiture La voiture à déplacer
 */
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr)
{
printf("ATTENTION : cette fonction risque fortement de bloquer le programme dans une boucle infinie : son appel récursif ne se terminera \
       certainement jamais...\n");
    // indice de la voiture + identification de la voiture devant la voiture courante
    Voiture * voitureDevant = Voiture_trouverVoitureDevant(voiture);

    // On vérifie que la distance séparant les deux véhicules est supérieure à la
    // distance d'arrêt
    if (pow(voiture->vitesseInstantanee * 2, 2) != ( pow(voiture->posX - voitureDevant->posX, 2) + pow(voiture->posY - voitureDevant->posY,2) ))
    {
    	Voiture_bouger(voiture, listeCarr);

    }
    else
    {
    	if (voiture->posX == listeCarr[voiture->traceChoisi[1]].posX)
    	{
    		Voiture_deplacementVertical(voiture, voitureDevant);
    	}
    	else
    	{
    		if (voiture->posY == listeCarr[voiture->traceChoisi[1]].posY)
    		{
    			Voiture_deplacementHorizontal(voiture, voitureDevant, listeCarr);
    		}
    		else
    		{
    		    printf("Erreur : déplacement hors des routes");
    			exit(-1);
    		}
    	}
    }
}

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee)
{
    return 0;
}

Voiture * Voiture_trouverVoitureDevant(Voiture *voiture)
{
    return 0;
}


int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture)
{
    return 0;
}
