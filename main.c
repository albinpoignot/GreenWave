#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[])
{
    // Démarrage de la SDL et handle des erreurs
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    // ---------- VARIABLES LOCALES ------------
    SDL_Surface *ecran = NULL, *routesH = NULL, *routesV = NULL;
    Uint32 violet, blanc;

    SDL_Event event;
    SDL_Rect position;
    int continuer = 1;
    int i;
    // ------------------------------------------


    // Répétition des touches
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
    SDL_WM_SetCaption("Hello World ! window", NULL);


    // Paramêtrage couleur de fond
    violet = SDL_MapRGB(ecran->format, 138, 0, 143); // Couleur violette
    SDL_FillRect(ecran, NULL, violet); // Définition de la couleur de fond de l'écran

    // Création et initialisation du rectangle des routes verticales
    blanc = SDL_MapRGB(ecran->format, 255, 255, 255);
    routesH = SDL_CreateRGBSurface(SDL_HWSURFACE, 30, 400, 32, 0, 0, 0, 0);
    SDL_FillRect(routesH, NULL, blanc);
    position.x = 200;
    position.y = 20;
    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesH, NULL, ecran, &position);
        position.x += 100;
    }


    // Création et initialisation du rectangle des routes horizontales
    routesV = SDL_CreateRGBSurface(SDL_HWSURFACE, 400, 30, 32, 0, 0, 0, 0);
    SDL_FillRect(routesV, NULL, blanc);
    position.x = 120;
    position.y = 100;
    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesV, NULL, ecran, &position);
        position.y += 100;
    }

    SDL_Flip(ecran); /* On met à jour l'affichage */



    // Evite la fenêtre de se fermer toute seule
    while(continuer)
    {
        SDL_PollEvent(&event);

        switch(event.type) /* Test du type d'évènement */
        {
            case SDL_QUIT: /* Si c'est un évènement de type "Quitter" */
                continuer = 0;
                break;

            case SDL_KEYDOWN: /* Si appui d'une touche */
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_m:
                        SDL_WarpMouse(ecran->w / 2, ecran->h / 2);
                        break;
                }
                break;

        }

    }


    // Free des surfaces
    SDL_FreeSurface(routesH);
    SDL_FreeSurface(routesV);
    SDL_Quit();

    return EXIT_SUCCESS;

}


