/**
 * \file Voiture.c
 * \brief Module Voiture
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Voiture.h"

#define VITESSE_MAX 2
#define LONGUEUR_VOITURE 10

/**
 * \fn Voiture * Voiture_create(SDL_Surface * ecran, int indCarrEntree, int indCarrSortie, ListeCarrefours listeCarrefours, Chemins chemins, Traces traces)
 * \brief Alloue sur le tas une structure Voiture, sélectionne le tracé à suivre et retourne un pointeur sur cette Voiture
 *
 * \param ecran La SDL_Surface où il va falloir dessiner le véhicule
 * \param indCarrEntree Indice du Carrefour duquel la voiture va entrer
 * \param indCarrSortie Indice du Carrefour duquel la voiture va sortir
 * \param chemins Tableau Chemins
 * \param traces Tableau Traces
 * \return La structure Voiture nouvellement allouée, prête à être déplacée
 */
Voiture * Voiture_create(SDL_Surface * ecran, int indCarrEntree, int indCarrSortie, ListeCarrefours listeCarrefours, Chemins chemins, Traces traces)
{
    // Allocation mémoire
    Voiture * voit = NULL;
    voit = (Voiture *)malloc(sizeof(Voiture));

    // Dessin de la voiture
    voit->dessin = SDL_CreateRGBSurface(SDL_SWSURFACE, LONGUEUR_VOITURE, LONGUEUR_VOITURE, 32, 0, 0, 0, 0);
    SDL_FillRect(voit->dessin, NULL, SDL_MapRGB(ecran->format, 150, 150, 150));

    // Définition de la position
    voit->position.x = listeCarrefours[indCarrEntree]->posX;
    voit->position.y = listeCarrefours[indCarrEntree]->posY;

    // Définition du tracé
    voit->traceChoisi = Voiture_getTraces(indCarrEntree, indCarrSortie, chemins, traces);

    // Définition de la vitesse instantannée initiale
    voit->vitesseInstantanee = 0;

    voit->vitesseMax = 5;

    return voit;
}


/**
 * \fn int * Voiture_getTraces()
 * \brief Détermine un tracé alléatoirement
 *
 * \param indCarrEntree Indice du Carrefour d'entrée de la voiture
 * \param indCarrSortie Indice du Carrefour de sortie de la voiture
 * \param chemins Tableau Chemins
 * \param traces Tableau Traces
 *
 * \return Le tracé sélectionné
 */
int * Voiture_getTraces(int indCarrEntree, int indCarrSortie, Chemins chemins, Traces traces)
{
    int idTraceChoisi;
    int inverser = 0;
    int i;
    int * tracesPossibles;
    int * traceChoisi;

    if(indCarrEntree > indCarrSortie)
    {
        indCarrEntree = indCarrEntree + indCarrSortie;
        indCarrSortie = indCarrEntree - indCarrSortie;
        indCarrEntree = indCarrEntree - indCarrSortie;
        inverser = 1;
    }

    // indCarrEntree toujours inférieur à indCarrSortie
    // recherche dans le tableau chemins[][][] possible
    tracesPossibles = chemins[indCarrEntree][indCarrSortie];

    if(chemins[indCarrEntree][indCarrSortie][0] > 1)
    {
        i = chemins[indCarrEntree][indCarrSortie][0] - 1;
        idTraceChoisi = (rand()%(i)) + 1;
    }
    else
    {
        idTraceChoisi = 1;
    }

    idTraceChoisi = chemins[indCarrEntree][indCarrSortie][idTraceChoisi];

    if(inverser == 1)
    {
        traceChoisi = Voiture_inverserTraces(traces[idTraceChoisi]);
    }
    else
    {
        traceChoisi = traces[idTraceChoisi];
    }

    // Recherche de la dernière case
    i = 1;
    while(traceChoisi[i] != -1 && i <= 7)
    {
        i++;
    }

    // La dernière case devient le carrefour de sortie de la voiture
    traceChoisi[i] = indCarrSortie;

    // Le premier élément devient la position actuelle de la voiture,
    // soit son carrefour d'entrée
    traceChoisi[0] = indCarrEntree;

    return traceChoisi;


}

/**
 * \fn int * Voiture_inverserTraces(int * traces)
 * \brief Inverse les valeurs du tableau en paramètre
 *
 * \param traces Un tableau provenant d'un tableau Trace. La dernière case DOIT être égale à '-1'
 *
 * \return Le tracé retourné
 */
int * Voiture_inverserTraces(int * traces)
{
    int tab[8];
    int i,j;

    i = 1;
    j = traces[0];

    tab[0] = traces[0];

    // On inverse le tableau traces
    while(traces[i] != -1)
    {
        tab[j] = traces[i];
        i++;
        j--;
    }

    return tab;
}

/**
 * \fn void Voiture_destroy(Voiture *voiture);
 * \brief Libère la mémoire utilisée par la structure Voiture en paramêtre
 *
 * \param voiture La voiture à libérer
 */
void Voiture_destroy(Voiture * voiture)
{
    free(voiture->dessin);
    free(voiture);
}

/**
 * \fn void Voiture_deplacer(Voiture *voitureListeSegments listeSeg, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], int * nbVoituresDeplacement, int * nbVoituresArret));
 * \brief Définit la file de la voiture, la mets dedans et choisit le bon mode de déplacement
 *          [ traceChoisi[1], [traceChoisi[2] ]
 *
 * \param voiture La voiture à déplacer
 * \param listeSeg Tableau ListeSegments regroupant les Segments du quartier
 * \param listeCarr Tableau ListeCarrefours regroupant les Carrefours du quartier
 * \param voituresEnDeplacement Tableau contenant les voitures actuellement en déplacement
 * \param voituresArret Tableau contenant les voitures actuellement à l'arrêt
 * \param nbVoituresDeplacement Nombre de voitures actuellement en déplacement
 * \param nbVoituresArret Nombre de voitures actuellement à l'arrêt
 */
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], int * nbVoituresDeplacement, int * nbVoituresArret)
{
    // Phase 1 : définition des indices des carrefours
    int indiceCarrDest = voiture->traceChoisi[1];

    if(indiceCarrDest != -1)
    {
        Carrefour * nextCarrefour = listeCarr[voiture->traceChoisi[1]];
        Voiture * voitureDevant = Voiture_trouverVoitureDevant(voiture);

        // Phase 2 : définition de la file de la voiture
        //voiture->fileActuelle = listeSeg[indiceCarrSource][indiceCarrDest]->file;

        // Phase 3 : lancement du déplacement
        if(voiture->position.x == nextCarrefour->posX)
        {
            //Voiture_deplacementVertical(voiture, voitureDevant);
        }
        else
        {
            if(voiture->position.y == nextCarrefour->posY)
            {
                Voiture_deplacementHorizontal(voiture, voitureDevant, listeCarr);
            }
            else
            {
                printf("Voiture_deplacer : déplacement hors des routes\n");
                //exit(EXIT_FAILURE);
            }
        }
        // Phase 4 : définition de l'action à venir (arret ou deplacement)
        Voiture_bouger(voiture, listeCarr, voituresEnDeplacement, voituresArret, voitureDevant, nbVoituresDeplacement, nbVoituresArret);
    }
    else
    {
        voiture->vitesseInstantanee = 0;
    }

}

/**
 * \fn void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
 * \brief Déplacement de la voiture sur un axe horizontal. Gère l'accélération et la
 *          décélération en cas de besoin.
 *
 * \param voiture La voiture à déplacer
 * \param voitureDevant La voiture se trouvant devant la voiture à déplacer
 * \param listeCarr Tableau ListeCarrefours regroupant les Carrefours du quartier
 */
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
{
    // ----- Phase 1 : Définition des diverses distances
    int distanceArret = 0;
    int i;

    // A implémenter : prendre en compte l'accélération. Pour cela, le pas d'incrémentation de i doit
    // être l'accélération.

    for(i=1;i<VITESSE_MAX;i++)
    {
        distanceArret += i;
    }

    // Calcul de la distance actuelle entre les deux voitures
    int distanceEntreVoitures = 9999999;
    if(voitureDevant != NULL)
    {
        distanceEntreVoitures = pow(voiture->position.x - voitureDevant->position.x, 2) + pow(voiture->position.y - voitureDevant->position.y, 2);
    }

    Carrefour * carr = listeCarr[voiture->traceChoisi[1]]; // Prochain carrefour

    // Définition du sens de circulation
    int direction = 1;
    if(voiture->position.x > carr->posX) // Le véhicule va de droite gauche à droite
    {
        direction = -1;
    }

    // ----- Phase 2 : déplacement jusqu'au bout du segment
    // Si la distance est suffisante et que la voiture n'est pas trop proche du carrefour
    if(distanceEntreVoitures > pow(distanceArret,2) && (pow(voiture->position.x,2) < pow((carr->posX - direction * (distanceArret + LONGUEUR_VOITURE)),2)) )
    {
        // Accélération éventuelle
        if(voiture->vitesseInstantanee < VITESSE_MAX)
        {
            voiture->vitesseInstantanee += 1;
        }
    }
    else
    {
        if(voiture->traceChoisi[2] == -1 && voiture->vitesseInstantanee > 0)
        {
            voiture->vitesseInstantanee -= 1;
        }
        else
        {
            // Si on est à cet endroit et que ce n'est pas à cause de la distance entre les voitures
            // c'est que l'on doit changer de carrefour
            if(distanceEntreVoitures >= distanceArret)
            {
                // Sinon, on change les donnees de traceChoisi, on met à jour les files et on recommence
                // un déplacement
                int i;

                // ** Phase 3.1 : Mise à jour de traceChoisi
                i = 1;
                while(voiture->traceChoisi[i] != -1 && i <= 7)
                {
                    voiture->traceChoisi[i-1] = voiture->traceChoisi[i];
                    i++;
                }

                voiture->traceChoisi[i-1] = -1;

                // ** Phase 3.2 : Mise à jour des files et relancement du déplacement
                if(voiture->traceChoisi[2] != -1)
                {
                    // A implémenter

                    //ListeSegments listeSeg;
                    //Voiture_deplacer(voiture, listeSeg, listeCarr);
                }

            }
        }
    }

    voiture->position.x += voiture->vitesseInstantanee;

    // ----- Phase 3 : Arrêt du véhicule
    // En cas de feu rouge ou de voiture à l'arrêt devant, on ralentit jusqu'à l'arrêt

    // A implémenter


}

/**
 * \fn void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
 * \brief Déplacement de la voiture sur un axe vertical. Gère l'accélération et la
 *          décélération en cas de besoin.
 *
 * \param voiture La voiture à déplacer
 * \param voitureDevant La voiture se trouvant devant la voiture à déplacer
 * \param listeCarr Tableau ListeCarrefours regroupant les Carrefours du quartier
 */
void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
{
    // A implémenter
}


/**
 * \fn void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], Voiture * voitureDevant, int * nbVoituresDeplacement, int * nbVoituresArret)
 * \brief Décide si la voiture est en cours de déplacement ou non.
 *
 * \param voiture La voiture à déplacer
 * \param listeCarr Tableau ListeCarrefours contenant les Carrefours du quartier
 * \param voituresEnDeplacement[] Tableau des voitures actuellement en déplacement
 * \param voituresArret[] Tableau des voitures actuellement à l'arrêt
 * \param voitureDevant Voiture devant la voiture à déplacer
 * \param nbVoituresDeplacement Nombre de voitures actuellement en déplacement
 * \param nbVoituresArret Nombre de voitures actuellement à l'arrêt
 */
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], Voiture * voitureDevant, int * nbVoituresDeplacement, int * nbVoituresArret)
{
    // On vérifie que la distance séparant les deux véhicules est supérieure à la
    // distance d'arrêt
    int distance = 9999999;
    int trouve;
    int i;

    if(voitureDevant != NULL)
    {
        distance = ( pow(voiture->position.x - voitureDevant->position.x, 2) + pow(voiture->position.y - voitureDevant->position.y,2) );
    }

    if (pow(voiture->vitesseInstantanee * 30, 2) > distance || voiture->traceChoisi[1] == -1)
    {
        // Elle ne l'est pas, la voiture ne doit pas se déplacer
    	Voiture_tabArreter(voituresEnDeplacement, voituresArret, voiture, nbVoituresDeplacement, nbVoituresArret);
    }
    else
    {
        trouve = 0;
        i = 0;
        if(nbVoituresDeplacement == NULL)
        {
            *nbVoituresDeplacement = 0;
        }

        while(trouve == 0 && i <= *nbVoituresDeplacement - 1)
        {
            if(voituresEnDeplacement[i] == voiture)
            {
                trouve = 1;
            }
        }

        if(trouve == 0)
        {
            Voiture_tabDeplacer(voituresEnDeplacement, voituresArret, voiture, nbVoituresDeplacement, nbVoituresArret);
            nbVoituresDeplacement++;
        }
    }
}

/**
 * \fn void Voiture_tabDeplacer(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret)
 * \brief Insère la voiture dans le tableau voituresEnDeplacement et la retire du tableau voituresArret
 *
 * \param voituresEnDeplacement Tableau des voitures actuellement en déplacement
 * \param voituresArret Tableau des voitures actuellement à l'arrêt
 * \param voiture Voiture concernée par le traitement
 * \param nbVoituresDeplacement Nombre de voitures actuellement en déplacement
 * \param nbVoituresArret Nombre de voitures actuellement à l'arrêt
 */
void Voiture_tabDeplacer(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret)
{
    Voiture ** tabVoitTemp = NULL;

    // Phase 1 : ajout de la voiture dans le tableau voituresEnDeplacement[]
    if(*nbVoituresDeplacement != 0)
    {
        tabVoitTemp = (Voiture **) realloc(voituresEnDeplacement, ((size_t)*nbVoituresDeplacement + 1) * sizeof(Voiture *));
        //free(voituresEnDeplacement[*nbVoitureDeplacement]);

        if(tabVoitTemp == NULL)
        {
            printf("Voiture_tabDeplacer : Ré-allocation du tableau voituresEnDeplacement impossible\n");
        }
        else
        {
            voituresEnDeplacement = tabVoitTemp;
            voituresEnDeplacement[nbVoituresDeplacement[0]] = voiture;
        }
    }
    else
    {
        voituresEnDeplacement[0] = voiture;
    }


    // Phase 2 : suppression de la voiture dans le tableau voituresArret
    if(*nbVoituresArret > 1)
    {
        tabVoitTemp = (Voiture **) realloc(voituresArret, (size_t)(*nbVoituresArret - 1) * sizeof(Voiture *));

        if(tabVoitTemp == NULL)
        {
            printf("Voiture_tabDeplacer : Ré-allocation du tableau voituresArret impossible");
            //exit(EXIT_FAILURE);
        }
        else
        {
            voituresArret = tabVoitTemp;
        }
    }
    else
    {
        voituresArret[0] = NULL;
    }
}

/**
 * \fn void Voiture_tabArreter(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret)
 * \brief Insère la voiture dans le tableau voituresArret et la retire du tableau voituresEnDeplacement
 *
 * \param voituresEnDeplacement Tableau des voitures actuellement en déplacement
 * \param voituresArret Tableau des voitures actuellement à l'arrêt
 * \param voiture Voiture concernée par le traitement
 * \param nbVoituresDeplacement Nombre de voitures actuellement en déplacement
 * \param nbVoituresArret Nombre de voitures actuellement à l'arrêt
 */
void Voiture_tabArreter(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret)
{
    Voiture ** tabVoitTemp = NULL;

    // Phase 1 : ajout de la voiture dans le tableau voituresEnDeplacement[]
    if(*nbVoituresArret != 0)
    {
        tabVoitTemp = (Voiture **) realloc(voituresArret, ((size_t)*nbVoituresArret + 1) * sizeof(Voiture *));
        //free(voituresEnDeplacement[*nbVoitureDeplacement]);

        if(tabVoitTemp == NULL)
        {
            printf("Voiture_tabArreter : Ré-allocation du tableau voituresArret impossible\n");
        }
        else
        {
            voituresArret = tabVoitTemp;
            voituresArret[nbVoituresArret[0]] = voiture;
        }
    }
    else
    {
        voituresArret[0] = voiture;
    }


    // Phase 2 : suppression de la voiture dans le tableau voituresArret
    if(*nbVoituresDeplacement > 1)
    {
        tabVoitTemp = (Voiture **) realloc(voituresEnDeplacement, (size_t)(*nbVoituresDeplacement - 1) * sizeof(Voiture *));

        if(tabVoitTemp == NULL)
        {
            printf("Voiture_tabArreter : Ré-allocation du tableau voituresEnDeplacement impossible");
            //exit(EXIT_FAILURE);
        }
        else
        {
            voituresEnDeplacement = tabVoitTemp;
        }
    }
    else
    {
        voituresEnDeplacement[0] = NULL;
    }



}

/**
 * \fn Voiture * Voiture_trouverVoitureDevant(Voiture *voiture)
 * \brief Trouve et retourne la voiture se trouvant devant la voiture en paramètre
 *
 * \param voiture Voiture dont on recherche celle de devant
 *
 * \return Pointeur sur la voiture devant celle en paramètre
 */
Voiture * Voiture_trouverVoitureDevant(Voiture *voiture)
{
    // A implémenter
    return 0;
}

/**
 * \fn  int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture)
 * \brief Trouve et retourne l'indice de la voiture dans sa file actuelle
 *
 * \param voiture Voiture dont on recherche l'indice
 *
 * \return Indice de la voiture dans sa file
 */
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture)
{
    return 0;
}
