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
    SDL_Surface *ecran = NULL, *rectangle = NULL, *zozor = NULL;
    SDL_Rect position;

    SDL_Event event;
    SDL_Event event2;
    int continuer = 1;
    int tpsActuel = 0, tpsPrecedent = 0;
    // ------------------------------------------


    SDL_EnableKeyRepeat(10, 10);


    // Ouverture d'une fenêtre : 640*480, couleurs 32b, on utilise la mém. vidéo
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    // En cas d'erreur à l'ouverture
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    // Titre de la fenêtre
    SDL_WM_SetCaption("Hello World ! window", NULL);


    // Paramêtrage couleur de fond
    Uint32 violet = SDL_MapRGB(ecran->format, 138, 0, 143); // Couleur violette
    SDL_FillRect(ecran, NULL, violet); // Définition de la couleur de fond de l'écran





    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
    SDL_Rect positionZozor;
    /* On centre zozor à l'écran */
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);


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
                    case SDLK_UP: // Flèche haut
                        positionZozor.y--;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        positionZozor.x--;
                        break;
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_m:
                        SDL_WarpMouse(ecran->w / 2, ecran->h / 2);
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) /* On arrête le programme si on a fait un clic droit */
                {
                    positionZozor.x = event.button.x; /* On change les coordonnées de Zozor */
                    positionZozor.y = event.button.y;
                }
                break;

        }

        tpsActuel = SDL_GetTicks();

        if(tpsActuel - tpsPrecedent > 15)
        {
            if(positionZozor.x < ecran->w)
            {
                positionZozor.x++;
            }
            else
            {
                positionZozor.x = 0;
            }
            tpsPrecedent = tpsActuel;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); /* On efface l'écran */
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); /* On place zozor à sa nouvelle position */
        SDL_Flip(ecran); /* On met à jour l'affichage */

    }




    // Free des surfaces
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(zozor);
    SDL_Quit();

    return EXIT_SUCCESS;

}


