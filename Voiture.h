#ifndef VOITURE_H
#define VOITURE_H

#include <SDL/SDL.h>

#include "Feu.h"
#include "Segment.h"

typedef struct Voiture Voiture;
struct Voiture {
    // Variables initialisées par Voiture_init()
    // et identiques pour chaque structure
    int vitesseMax;
    int tpsDeReac;
    int acceleration;
    int distanceSecuArret;

    // Variables non initialisées et modifiables
    // indépendement par chaque strucure
    int posX;
    int posY;
    SDL_Rect position;
    int vitesseInstantanee;
    int distanceSecuMouvement; // a supprimer ?
    struct File * fileActuelle; // Pointeur sur un tableau externe
    int * traceChoisi;
    SDL_Surface * dessin;
};

// Initialisation et destruction d'une voiture
Voiture * Voiture_create(SDL_Surface * ecran);
void Voiture_destroy(Voiture *voiture);

// Déplacement
//void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr);
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr, Voiture * voitureEnDeplacement[], Voiture * voitureArret[]);
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr);
//void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr);
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr, Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voitureDevant);

void Voiture_tabDeplacer(Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voiture);
void Voiture_tabArreter(Voiture * voitureEnDeplacement[], Voiture * voitureArret[], Voiture * voiture);

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee);
Voiture * Voiture_trouverVoitureDevant(Voiture *voiture);
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture);

#endif // VOITURE_H
