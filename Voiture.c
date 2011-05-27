#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Voiture.h"

// Initialisation et destruction d'une voiture
/**
 * \fn Voiture * Voiture_create()
 * \brief Alloue une correctement une structure Voiture et la retourne
 *
 * \return La structure Voiture nouvellement allouée
 */
Voiture * Voiture_create()
{
    Voiture * voit = NULL;

    voit = (Voiture *)malloc(sizeof(Voiture));

    return voit;
}

/**
 * \fn void Voiture_destroy(Voiture *voiture);
 * \brief Libère la mémoire utilisée par la structure Voiture en paramêtre
 *
 * \param voiture La voiture à libérer
 */
void Voiture_destroy(Voiture *voiture)
{
    free(voiture);
}

/**
 * \fn void Voiture_deplacer(Voiture *voiture);
 * \brief Définit la file de la voiture, la mets dedans et lance le déplacement sur le segment
 *          [ traceChoisi[1], [traceChoisi[2] ]
 *
 * \param voiture La voiture à déplacer
 */
void Voiture_deplacer(Voiture *voiture, ListeSegments listeSeg)
{
    // Phase 1 : définition des indices des carrefours
    int indiceCarrSource = voiture->traceChoisi[0];
    int indiceCarrDest = Voiture_definirIndiceCarrefourDest(voiture->traceChoisi[0], voiture->traceChoisi[1]);

    // Phase 2 : définition de la file de la voiture
    voiture->fileActuelle = listeSeg[indiceCarrSource][indiceCarrDest]->file;

    // Phase 3 : lancement du déplacement
    Voiture_bouger(voiture);
}

/**
 * \fn void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant)
 * \brief Déplacement de la voiture sur un axe horizontal. Gère l'accélération et la
 *          décélération en cas de besoin.
 *
 * \param voiture La voiture à déplacer
 * \param voitureDevant La voiture se trouvant devant la voiture à déplacer
 */
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant, ListeCarrefours listeCarr)
{

    // ----- Phase 1 : Définition des diverses distances
    int distanceArret = voiture->vitesseInstantanee * 2; // Distance d'arret = v * 2 secondes
    distanceArret = (int)pow(distanceArret, 2); // Pour simplification des calculs futurs

    // Calcul de la distance actuelle entre les deux voitures
    int distanceEntreVoitures = (int)pow(voiture->posX - voitureDevant->posX, 2) + (int)pow(voiture->posY - voitureDevant->posY, 2);

    // ----- Phase 2 : déplacement jusqu'au bout du segment
    // Si la distance est suffisante et que la voiture n'est pas trop proche du carrefour
    while(distanceEntreVoitures > distanceArret && (voiture->posX != listeCarr[voiture.traceChoisi[1]].posX - distanceArret) )
    {
        // ** Phase 2.1 : Accélération éventuelle et calcul de la nouvelle distance d'arret
        if(voiture->vitesseInstantanee < vitesseMax)
        {
            voiture->vitesseInstantanee += 1;
        }
    }

}


void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant) {}

void Voiture_bouger(Voiture *voiture) { }

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee)
{
    return 0;
}

int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture)
{
    return 0;
}
