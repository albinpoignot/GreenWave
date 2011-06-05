#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "Configurations.h"

#define LONGUEUR_ROUTES 500
#define LARGEUR_ROUTES 40
#define ESPACE_ROUTES 95 // espaceRoutes = (LONGUEUR_ROUTES - 3*LARGEUR_ROUTES) / 4
#define PADDING 40

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

    int i;

    ListeCarrefours * listeCarrefours;
    ListeSegments * listeSegments;
    int *** chemins = NULL;
    Traces * traces;
    Voiture ** voitureEnDeplacement;
    Voiture ** voitureArret;
    // ------------------------------------------

    ecran = lancerEcran();

    /**************************************************
     * Phase 3 : Initialisation du dessin du quartier *
     **************************************************/
    dessinerQuartier(ecran);


    //traces = (Traces *) malloc(62 * 5 * sizeof(int));
    /**************************************************
     * Phase 2 : Initialisation des variables locales *
     **************************************************/
    printf("%d\n\n", sizeof(ListeCarrefours));
    //init_config(listeSegments, listeCarrefours, *traces, chemins, PADDING, ESPACE_ROUTES, LARGEUR_ROUTES);
    listeCarrefours = init_listeCarrefours(PADDING, ESPACE_ROUTES, LARGEUR_ROUTES);
    printf("finished\n");
    //listeSegments = init_listeSegments(listeCarrefours);
    //traces = init_traces();
    //chemins = init_chemins();



    /*Voiture * voit1 = Voiture_create(ecran);
    Segment * seg = listeSegments[2][6];
    //voit1->position->x = listeSegments[2][6]->carrefourEntree->posX;
    voit1->position.x = seg->carrefourEntree->posX;
    voit1->position.y = seg->carrefourEntree->posY;
    voit1->traceChoisi = traces[41];*/

    //voit1->fileActuelle =


    /*SDL_BlitSurface(voit1->dessin, NULL, ecran, &voit1->position);
    SDL_Flip(ecran);*/



   /*voitureArret = NULL;
    voitureArret = malloc(sizeof(Voiture *));

    if(voitureArret == NULL)
    {
        printf("MAIN : Ré-allocation du tableau voitureArret impossible");
        exit(EXIT_FAILURE);
    }
    else
    {
        voitureArret[0] = voit1;
    }

    Voiture_tabDeplacer(voitureEnDeplacement, voitureArret, voit1);


    for(i=0; i<=50; i++)
    {
        Voiture_deplacer(voit1, *listeSegments, *listeCarrefours, voitureEnDeplacement, voitureArret);
        printf("----------\n");
        printf("voit - posX : %d / posY : %d\n", voit1->posX, voit1->posY);
        printf("----------\n");

        SDL_Flip(ecran);
    }*/

    //SDL_Flip(ecran);

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

    }


    /**************************************
     * Phase 5 : Libération de la mémoire *
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
printf("lancer_ecran() fin\n");
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
printf("start to draw the screen\n");
    Uint32 violet, blanc;
    SDL_Surface *routesH = NULL, *routesV = NULL;
    SDL_Rect position;
    int i;

    if(ecran == NULL)
    {
        printf("Il y a un problème à l'initialisation de l'écran");
        exit(EXIT_FAILURE);
    }
printf("dessin %d\n", 1);
    // Paramêtrage couleur de fond
    violet = SDL_MapRGB(ecran->format, 138, 0, 143); // Couleur violette
    SDL_FillRect(ecran, NULL, violet); // Définition de la couleur de fond de l'écran
printf("dessin %d\n", 2);
    // --------------------------------------------
    // Phase 1 : Routes horizontales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes verticales
    blanc = SDL_MapRGB(ecran->format, 255, 255, 255);
    printf("dessin %d - %d\n", 2,1);
    routesV = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_ROUTES, LONGUEUR_ROUTES, 32, 0, 0, 0, 0);
    printf("dessin %d - %d\n", 2,2);
    SDL_FillRect(routesV, NULL, blanc);
printf("dessin %d\n", 3);
    // La première route sera à cette position
    position.x = ESPACE_ROUTES + PADDING;
    position.y = PADDING;
printf("dessin %d\n", 4);
    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesV, NULL, ecran, &position);
        position.x += ESPACE_ROUTES + LARGEUR_ROUTES;
    }
printf("dessin %d\n", 5);
    // --------------------------------------------
    // Phase 1 : Routes verticales
    // --------------------------------------------

    // Création et initialisation du rectangle des routes horizontales
    routesH = SDL_CreateRGBSurface(SDL_HWSURFACE, LONGUEUR_ROUTES, LARGEUR_ROUTES, 32, 0, 0, 0, 0);
    SDL_FillRect(routesH, NULL, blanc);
printf("dessin %d\n", 6);
    // La première route verticale sera à cette position
    position.x = PADDING;
    position.y = ESPACE_ROUTES + PADDING;
printf("dessin %d\n", 7);
    for(i = 0; i <= 2; i++)
    {
        SDL_BlitSurface(routesH, NULL, ecran, &position);
        position.y += ESPACE_ROUTES + LARGEUR_ROUTES;
    }
printf("dessin %d\n", 8);

    // Mise à jour de l'affichage
    SDL_Flip(ecran);

printf("finish to draw the screen\n");
}

/**
 * \fn void destroyAll()
 * \brief Détruit tous les objets alloués lors de l'affichage du quartier
 */
void destroyAll()
{

}


