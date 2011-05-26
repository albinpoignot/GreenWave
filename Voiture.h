/*#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED

typedef struct {

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
    int * fileActuelle; // Pointeur sur un tableau externe
    int * traceChoisi;
} Voiture;

// Initialisation et destruction d'une voiture
void voiture_init(Voiture *voiture);
void voiture_destroy(Voiture *voiture);

// Déplacement
void voiture_deplacer(Voiture *voiture);
void voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant);
void voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant);
void voiture_bouger(Voiture *voiture);

// Fonction intermédiaire
int voiture_definirIndiceCarrefourDest(int depart, int arrivee);
int voiture_trouverIndiceVoitureDansFile(Voiture *voiture);

#endif // VOITURE_H_INCLUDED
*/
