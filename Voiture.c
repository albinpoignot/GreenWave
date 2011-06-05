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
Voiture * Voiture_create(SDL_Surface * ecran)
{
    Voiture * voit = NULL;

    voit = (Voiture *)malloc(sizeof(Voiture));
    SDL_Surface * dess = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 15, 32, 0, 0, 0, 0);
    SDL_FillRect(dess, NULL, SDL_MapRGB(ecran->format, 150, 150, 150));

    voit->dessin = dess;

    voit->position.x = 400;
    voit->position.y = 400;

    voit->vitesseInstantanee = 0;

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
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr, Voiture * voitureEnDeplacement[], Voiture * voitureArret[])
{
printf("dep %d \n", 1);
    // Phase 1 : définition des indices des carrefours
    int indiceCarrSource = voiture->traceChoisi[0];
    int indiceCarrDest = Voiture_definirIndiceCarrefourDest(voiture->traceChoisi[0], voiture->traceChoisi[1]);
    Voiture * voitureDevant = Voiture_trouverVoitureDevant(voiture);
printf("dep %d \n", 2);
    // Phase 2 : définition de la file de la voiture
    //voiture->fileActuelle = listeSeg[indiceCarrSource][indiceCarrDest]->file;
printf("dep %d \n", 3);
int i;
for(i=0; i<=20; i++)
{
    printf("listCarr[%d] = %d\n", i, listeCarr[i]);
}

for(i=0;i<=3;i++)
{
    printf("traceChoisi[%d] = %d\n", i, voiture->traceChoisi[i]);
}
printf("listeCarr bla bla : %d\n", voiture->traceChoisi[1]);
    // Phase 3 : lancement du déplacement
    if (voiture->posX == listeCarr[voiture->traceChoisi[1]]->posX)
    {
printf("dep %d \n", 4);
        //Voiture_deplacementVertical(voiture, voitureDevant);
    }
    else
    {
printf("dep %d \n", 5);
        if (voiture->posY == listeCarr[voiture->traceChoisi[1]]->posY)
        {
printf("dep %d \n", 6);
            Voiture_deplacementHorizontal(voiture, voitureDevant, listeCarr);
printf("dep %d \n", 7);
        }
        else
        {
            printf("Voiture_deplacer : déplacement hors des routes");
            exit(EXIT_FAILURE);
        }
    }
printf("dep %d \n", 8);
    // Phase 4 : définition de l'action à venir (arret ou deplacement)
    Voiture_bouger(voiture, listeCarr, voitureEnDeplacement, voitureArret, voitureDevant);
printf("dep %d \n", 9);
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
printf("depHor %d \n", 1);
    // ----- Phase 1 : Définition des diverses distances
    int distanceArret = voiture->vitesseInstantanee * 2; // Distance d'arret = v * 2 secondes
    distanceArret = pow(distanceArret, 2); // Pour simplification des calculs futurs
printf("depHor %d \n", 2);
    // Calcul de la distance actuelle entre les deux voitures
    int distanceEntreVoitures = 9999;
    if(voitureDevant != NULL)
    {
        distanceEntreVoitures = pow(voiture->posX - voitureDevant->posX, 2) + pow(voiture->posY - voitureDevant->posY, 2);
    }

printf("depHor %d \n", 3);
    // ----- Phase 2 : déplacement jusqu'au bout du segment
    // Si la distance est suffisante et que la voiture n'est pas trop proche du carrefour
    Carrefour * carr = listeCarr[voiture->traceChoisi[1]];
printf("depHor %d \n", 4);
    //while(distanceEntreVoitures > distanceArret && (voiture->posX != (carr.posX - distanceArret)) )
    if(distanceEntreVoitures > distanceArret && (voiture->posX != (carr->posX - distanceArret)) )
    {
printf("depHor %d \n", 5);
        // ** Phase 2.1 : Accélération éventuelle et calcul de la nouvelle distance d'arret
        if(voiture->vitesseInstantanee < VITESSE_MAX)
        {
printf("depHor %d \n", 6);
            voiture->vitesseInstantanee += 1;
            //distanceArret = pow(voiture->vitesseInstantanee * 2,2);
        }
printf("depHor %d \n", 7);
        // ** Phase 2.2 : Déplacement
        voiture->posX += voiture->vitesseInstantanee;
printf("depHor %d \n", 8);
    }

    // ----- Phase 3 : Arrêt du véhicule
    // En cas de feu rouge ou de voiture à l'arrêt devant, on ralentit jusqu'à l'arrêt
//printf("Voiture.c, fct deplacementHorizontal(), phase 3, implémenter les feux rouges\n");
    if(distanceEntreVoitures <= distanceArret)
    {
printf("depHor %d \n", 9);
        //while(voiture->vitesseInstantanee > 0)
        if(voiture->vitesseInstantanee > 0)
        {
            voiture->vitesseInstantanee -= 1;
            voiture->posX += voiture->vitesseInstantanee;
        }
printf("depHor %d \n", 10);
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
//printf("Voiture.c, fct deplacementHorizontal(), phase 3.2, défiler la voiture");

        if(voiture->traceChoisi[2] != NULL)
        {
            //ListeSegments listeSeg;
            //Voiture_deplacer(voiture, listeSeg, listeCarr);
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
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr, Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voitureDevant)
{
    // indice de la voiture + identification de la voiture devant la voiture courante

    // On vérifie que la distance séparant les deux véhicules est supérieure à la
    // distance d'arrêt
printf("bou %d\n", 1);
    int distance = 9999;

    if(voitureDevant != NULL)
    {
        distance = ( pow(voiture->posX - voitureDevant->posX, 2) + pow(voiture->posY - voitureDevant->posY,2) );
    }

    if (pow(voiture->vitesseInstantanee * 2, 2) < distance)
    {
        // Elle ne l'est pas, la voiture ne doit pas se déplacer
    	//Voiture_bouger(voiture, listeCarr);
    	Voiture_tabArreter(voitureEnDeplacement, voitureArret, voiture);
printf("bou %d\n", 1);
    }
    else
    {
printf("bou %d\n", 2);
        Voiture_tabDeplacer(voitureEnDeplacement, voitureArret, voiture);

    	/*if (voiture->posX == listeCarr[voiture->traceChoisi[1]].posX)
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
    	}*/
printf("bou %d\n", 3);
    }
}

void Voiture_tabDeplacer(Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voiture)
{
    int nvTaille = (sizeof(voitureEnDeplacement) / sizeof(Voiture *)) + 1;

    // Phase 1 : ajout de la voiture dans le tableau voitureEnDeplacement[]
    voitureEnDeplacement = (Voiture **) realloc(voitureEnDeplacement, nvTaille);

    if(voitureEnDeplacement == NULL)
    {
        printf("Voiture_tabDeplacer : Ré-allocation du tableau voitureEnDeplacement impossible");
        exit(EXIT_FAILURE);
    }
    else
    {
        voitureEnDeplacement[nvTaille - 1] = voiture;
    }

    // Phase 2 : suppression de la voiture dans le tableau voitureArret
    nvTaille = (sizeof(voitureArret) / sizeof(Voiture *)) - 1;
    printf("ok\n");
    if(nvTaille > 1)
    {
        voitureArret = (Voiture **) realloc(voitureArret, (sizeof(voitureArret) / sizeof(Voiture *)) - 1);
        printf("ok2\n");
        if(voitureArret == NULL)
        {
            printf("Voiture_tabDeplacer : Ré-allocation du tableau voitureArret impossible");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("ok3\n");
        voitureArret[0] = NULL;
        printf("ok4\n");
    }

}

void Voiture_tabArreter(Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voiture)
{
    int nvTailleArr = (sizeof(voitureArret) / sizeof(Voiture *)) + 1;

    // Phase 1 : ajout de la voiture dans le tableau voitureEnDeplacement[]
    voitureArret = (Voiture *) realloc(voitureArret, nvTailleArr);

    if(voitureArret == NULL)
    {
        printf("Voiture_tabArreter : Ré-allocation du tableau voitureArret impossible");
        exit(EXIT_FAILURE);
    }
    else
    {
        voitureArret[nvTailleArr - 1] = voiture;
    }

    // Phase 2 : suppression de la voiture dans le tableau voitureArret
    voitureEnDeplacement = (Voiture *) realloc(voitureEnDeplacement, (sizeof(voitureEnDeplacement) / sizeof(Voiture *)) - 1);
    if(voitureArret == NULL)
    {
        printf("Voiture_tabDeplacer : Ré-allocation du tableau voitureArret impossible");
        exit(EXIT_FAILURE);
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
