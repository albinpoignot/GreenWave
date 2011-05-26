#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "Configurations.h"

SDL_Surface * lancerEcran();
void dessinerQuartier(SDL_Surface * ecran);

int main(int argc, char *argv[])
{
    /*****************************************
     * Phase 1 : Initialisation du programme *
     *****************************************/
    // Démarrage de la SDL et handle des erreurs
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    // ---------- VARIABLES LOCALES ------------
    SDL_Surface *ecran = NULL;
    SDL_Event event;
    int continuer = 1;
    // ------------------------------------------

    ecran = lancerEcran();

    /**************************************************
     * Phase 2 : Initialisation du dessin du quartier *
     **************************************************/
    dessinerQuartier(ecran);

    /************************************
     * Phase 3 : Lancement du programme *
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

    }


    /**************************************
     * Phase 4 : Libération de la mémoire *
     **************************************/
    // Free des surfaces
//    SDL_FreeSurface(routesH);
//   SDL_FreeSurface(routesV);
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
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

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
void dessinerQuartier(SDL_Surface * ecran)
{
    Uint32 violet, blanc;
    SDL_Surface *routesH = NULL, *routesV = NULL;
    SDL_Rect position;
    int i;
    SDL_PixelFormat * test;

    if(ecran == NULL)
    {
        printf("There is a fucking big problem !");
    }

    // Paramêtrage couleur de fond
    violet = SDL_MapRGB(ecran->format, 138, 0, 143); // Couleur violette
    SDL_FillRect(ecran, NULL, violet); // Définition de la couleur de fond de l'écran

    // --------------------------------------------
    // Phase 1 : Routes horizontales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes verticales
    blanc = SDL_MapRGB(ecran->format, 255, 255, 255);
    routesV = SDL_CreateRGBSurface(SDL_HWSURFACE, largeurRoutes, longueurRoutes, 32, 0, 0, 0, 0);
    SDL_FillRect(routesV, NULL, blanc);

    // La première route sera à cette position
    position.x = espaceRoutes + padding;
    position.y = padding;

    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesV, NULL, ecran, &position);
        position.x += espaceRoutes + largeurRoutes;
    }

    // --------------------------------------------
    // Phase 1 : Routes verticales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes horizontales
    routesH = SDL_CreateRGBSurface(SDL_HWSURFACE, longueurRoutes, largeurRoutes, 32, 0, 0, 0, 0);
    SDL_FillRect(routesH, NULL, blanc);

    // La première route verticale sera à cette position
    position.x = padding;
    position.y = espaceRoutes + padding;

    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesH, NULL, ecran, &position);
        position.y += espaceRoutes + largeurRoutes;
    }


    // Mise à jour de l'affichage
    SDL_Flip(ecran);
}

/**
 * \fn void destroyAll()
 * \brief Détruit tous les objets alloués lors de l'affichage du quartier
 */
void destroyAll()
{

}


