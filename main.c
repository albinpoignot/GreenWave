#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur alors...
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Ecriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    SDL_Surface *ecran = NULL, *rectangle = NULL;
    SDL_Rect position;

    // Ouverture d'une fenêtre : 640*480, couleurs 32b, on utilise la mém. vidéo
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

    if (ecran == NULL) // Si l'ouverture a échoué, on écrit l'erreur et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    // Titre de la fenêtre
    SDL_WM_SetCaption("Hello World ! window", NULL);


    // Quelques tests
    Uint32 violet = SDL_MapRGB(ecran->format, 138, 0, 143);
    SDL_FillRect(ecran, NULL, violet);

    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));


    position.x = 0;
    position.y = 0;

    SDL_BlitSurface(rectangle, NULL, ecran, &position);












    SDL_Flip(ecran);

    pause();

    SDL_FreeSurface(rectangle);
    SDL_Quit();

    return EXIT_SUCCESS;
}


void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
