#ifndef VOITURE_H
#define VOITURE_H

#include <SDL/SDL.h>

#include "Feu.h"
#include "Segment.h"

/**
 * \struct Feu
 * \brief Structure représentant une voiture
 */
typedef struct Voiture Voiture;
struct Voiture {
    // Variables initialisées par Voiture_init()
    // et identiques pour chaque structure
    int vitesseMax; /*!< Vitesse maximum, identique pour toutes les voitures */
    int acceleration; /*!< Accélération du véhicule, identique à toutes les voitures */
    int distanceSecuArret; /*!< Distance de sécurité à respecter lorsque la voiture est à l'arrêt, identique à toutes les voitures */

    // Variables non initialisées et modifiables
    // indépendement par chaque strucure
    SDL_Rect position; /*!< Position de la voiture à l'écran */
    int vitesseInstantanee; /*!< Vitesse actuelle de la voiture */
    struct File * fileActuelle; /*!< File actuelle de la voiture */
    int * traceChoisi; /*!< Tracé que la voiture doit suivre avant de sortir du quartier */
    SDL_Surface * dessin; /*!< Dessin de la voiture à l'écran */
};

// Initialisation et destruction d'une voiture
Voiture * Voiture_create(SDL_Surface * ecran, int indCarrEntree, int indCarrSortie, ListeCarrefours listeCarrefours, Chemins chemins, Traces traces);
void Voiture_destroy(Voiture * voiture);

// Déplacement
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], int * nbVoituresDeplacement, int * nbVoituresArret);
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr);
void Voiture_bouger(Voiture *voiture, ListeCarrefours listeCarr, Voiture * voituresEnDeplacement[], Voiture * voituresArret[], Voiture * voitureDevant, int * nbVoituresDeplacement, int * nbVoituresArret);

//void Voiture_tabDeplacer(Voiture * voituresEnDeplacement[], Voiture * voituresArret[], Voiture * voiture);
void Voiture_tabDeplacer(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret);
void Voiture_tabArreter(Voiture ** voituresEnDeplacement, Voiture ** voituresArret, Voiture * voiture, int * nbVoituresDeplacement, int * nbVoituresArret);

// Fonctions intermédiaires
Voiture * Voiture_trouverVoitureDevant(Voiture *voiture);
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture);
int * Voiture_inverserTraces(int * traces);
int * Voiture_getTraces(int indCarrEntree, int indCarrSortie, Chemins chemins, Traces traces);

#endif // VOITURE_H
