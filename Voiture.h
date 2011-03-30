#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED

typedef struct {

    // Variables initialisées par Voiture_init()
    // et identiques pour chaque structure
    int vitesseMax;
    int tpsDeReac;
    int acceleration;
    int distanceSecuArret;

    // Variables non initialisées et modifiable
    // indépendement par chaque strucure
    int posX;
    int posY;
    int vitesseInstantanee;
    int distanceSecuMvt; // A supprimer ?
} Voiture;

void Voiture_init(Voiture *voiture);

void Voiture_deplacer(Voiture *voiture, int dest);

void Voiture_deplacementVertical(Voiture *voiture, int coor[]);

void Voiture_deplacementHorizontal(Voiture *voiture, int coor[]);

#endif // VOITURE_H_INCLUDED
