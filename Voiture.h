#ifndef VOITURE_H
#define VOITURE_H

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
    int vitesseInstantanee;
    int distanceSecuMouvement; // a supprimer ?
    struct File * fileActuelle; // Pointeur sur un tableau externe
    int * traceChoisi;
};

// Initialisation et destruction d'une voiture
Voiture * Voiture_create();
void Voiture_destroy(Voiture *voiture);

// Déplacement
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr);
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr);
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr);

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee);
Voiture * Voiture_trouverVoitureDevant(Voiture *voiture);
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture);

#endif // VOITURE_H
