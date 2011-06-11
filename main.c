/**
 * \file main.c
 * \brief Simulation de trafic à petite échelle
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 *
 * Simule la circulation de véhicule dans un quartier simple avec des feux rouges. Vise à étudier
 * l'impact d'une vague verte sur le trafic et la consommation de carburant
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "Configurations.h"

#define LONGUEUR_ROUTES 500
#define LARGEUR_ROUTES 40
#define ESPACE_ROUTES 95 // espaceRoutes = (LONGUEUR_ROUTES - 3*LARGEUR_ROUTES) / 4
#define PADDING 40

SDL_Surface * lancerEcran();
void dessinerQuartier(SDL_Surface * ecran, SDL_Surface * routesH, SDL_Surface * routesV);

int main(int argc, char *argv[])
{
    /*****************************************
     * Phase 1 : Initialisation du programme *
     *****************************************/
    // Démarrage de la SDL et handle des erreurs
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    // ---------- VARIABLES LOCALES ------------
    SDL_Surface *ecran = NULL;
    SDL_Event event;
    int continuer = 1;

    ListeCarrefours listeCarrefours;
    ListeSegments listeSegments;
    Chemins chemins;
    Traces traces;
    Voiture ** voituresEnDeplacement;
    Voiture ** voituresArret;
    int * nbVoituresDeplacement;
    int * nbVoituresArret;

    SDL_Surface * routeH = SDL_CreateRGBSurface(SDL_HWSURFACE, LONGUEUR_ROUTES, LARGEUR_ROUTES, 32, 0, 0, 0, 0);
    SDL_Surface * routeV = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_ROUTES, LONGUEUR_ROUTES, 32, 0, 0, 0, 0);
    // ------------------------------------------

    ecran = lancerEcran();

    /**************************************************
     * Phase 2 : Initialisation des variables locales *
     **************************************************/
    //init_config(listeSegments, listeCarrefours, *traces, chemins, PADDING, ESPACE_ROUTES, LARGEUR_ROUTES);
    init_listeCarrefours(listeCarrefours, PADDING, ESPACE_ROUTES, LARGEUR_ROUTES);
    init_listeSegments(listeSegments, listeCarrefours);
    init_traces(traces);
    init_chemins(chemins);

    srand(time(NULL)); // initialisation de rand()

    /**************************************************
     * Phase 3 : Initialisation du dessin du quartier *
     **************************************************/
    dessinerQuartier(ecran, routeH, routeV);

    /***********************************************
     * Phase TEST : Lancement manuel d'une voiture *
     ***********************************************/

    Voiture * voit1 = Voiture_create(ecran, 8, 12, listeCarrefours, chemins, traces);

    nbVoituresDeplacement = (int *)malloc(sizeof(int));
    nbVoituresArret = (int *)malloc(sizeof(int));

    *nbVoituresArret = 0;
    *nbVoituresDeplacement = 0;

    SDL_BlitSurface(voit1->dessin, NULL, ecran, &voit1->position);
    SDL_Flip(ecran);

    voituresArret = NULL;

    voituresArret = (Voiture **) malloc(sizeof(Voiture *));

    voituresEnDeplacement = NULL;

    voituresEnDeplacement = (Voiture **) malloc(sizeof(Voiture *));
    *voituresEnDeplacement = NULL;

    voituresArret[0] = voit1;

    Voiture_tabDeplacer(voituresEnDeplacement, voituresArret, voit1, nbVoituresDeplacement, nbVoituresArret);

    /************************************
     * Phase 4 : Lancement du programme *
     ************************************/
    // Evite à la fenêtre de se fermer toute seule
    while(continuer)
    {
        // On écoute les évènements
        SDL_PollEvent(&event);

        switch(event.type) // Test du type d'évènement
        {
            case SDL_QUIT: // Demande de fermeture : arrêt du programme
                continuer = 0;
                break;

            case SDL_KEYDOWN: // Appui sur une touche
                switch(event.key.keysym.sym) // Test de la touche appuyée
                {
                    case SDLK_ESCAPE: // Echap : ârrêt du programme
                        continuer = 0;
                        break;
                    case SDLK_m: // m : placement souris milieu de l'écran
                        SDL_WarpMouse(ecran->w / 2, ecran->h / 2);
                        break;
                    default:
                    break;
                }
                break;
            default:
            break;

        }

        if(voituresEnDeplacement != NULL)
        {
            // Prévoir une boucle sur tous les éléments de voituresEnDeplacement
            if(voituresEnDeplacement[0] == voit1)
            {
                Voiture_deplacer(voit1, listeSegments, listeCarrefours, voituresEnDeplacement, voituresArret, nbVoituresDeplacement, nbVoituresArret);
            }
        }

        dessinerQuartier(ecran, routeH, routeV);
        SDL_BlitSurface(voit1->dessin, NULL, ecran, &voit1->position);
        SDL_Flip(ecran);

    }


    /**************************************
     * Phase 5 : Libération de la mémoire *
     **************************************/
    // Free des surfaces
    SDL_FreeSurface(routeH);
    SDL_FreeSurface(routeV);
    free(voituresArret);
    free(voituresEnDeplacement);
    free(nbVoituresArret);
    free(nbVoituresDeplacement);

    Voiture_destroy(voit1);

    destroy_listeCarrefours(listeCarrefours);
    destroy_listeSegments(listeSegments);

    SDL_Quit();

    return EXIT_SUCCESS;

}

/**
 * \fn SDL_Surface * lancerEcran()
 * \brief Crée et retourne une nouvelle surface initialisée comme fenêtre principale de dimensions 800*600 en 32bits en utilisant la mém. vidéo
 *
 * \return La surface crée
 */
SDL_Surface * lancerEcran()
{
    SDL_Surface * ecran = NULL;

    // Paramétrage de la répétition des touches
    SDL_EnableKeyRepeat(10, 10);

    // Ouverture d'une fenêtre : 800*600, couleurs 32b, on utilise la mém. vidéo
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    // En cas d'erreur à l'ouverture
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Titre de la fenêtre
    SDL_WM_SetCaption("Green Wave", NULL);

    return ecran;
}

/**
 * \fn void dessinerQuartier(SDL_Surface * ecran)
 * \brief Se charge du dessin du quartier (3 routes verticlaes + 3 horizontales), routes blanches et fond violet
 *
 * \param ecran L'écran sur lequel dessiner le quartier
 */
void dessinerQuartier(SDL_Surface * ecran, SDL_Surface * routesH, SDL_Surface * routesV)
{
    Uint32 violet, blanc;
    SDL_Rect position;
    int i;

    if(ecran == NULL)
    {
        printf("Il y a un problème à l'initialisation de l'écran");
        exit(EXIT_FAILURE);
    }

    // Paramêtrage couleur de fond
    violet = SDL_MapRGB(ecran->format, 138, 0, 143); // Couleur violette
    SDL_FillRect(ecran, NULL, violet); // Définition de la couleur de fond de l'écran

    // --------------------------------------------
    // Phase 1 : Routes horizontales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes verticales
    blanc = SDL_MapRGB(ecran->format, 255, 255, 255);

    SDL_FillRect(routesV, NULL, blanc);

    // La première route sera à cette position
    position.x = ESPACE_ROUTES + PADDING;
    position.y = PADDING;

    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesV, NULL, ecran, &position);
        position.x += ESPACE_ROUTES + LARGEUR_ROUTES;
    }

    // --------------------------------------------
    // Phase 1 : Routes verticales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes horizontales
    SDL_FillRect(routesH, NULL, blanc);

    // La première route verticale sera à cette position
    position.x = PADDING;
    position.y = ESPACE_ROUTES + PADDING;

    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesH, NULL, ecran, &position);
        position.y += ESPACE_ROUTES + LARGEUR_ROUTES;
    }

}

/**
 * \fn void destroyAll()
 * \brief Détruit tous les objets alloués lors de l'affichage du quartier
 */
void destroyAll()
{

}


