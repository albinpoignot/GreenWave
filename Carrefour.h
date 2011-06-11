#ifndef CARREFOUR_H
#define CARREFOUR_H

#include "Feu.h"

#define MAX_CARREFOUR 21
#define MAX_FEU 4


/**
 * \struct Carrefour
 * \brief Carrefour du quartier
 *
 * Carrefour représente un carrefour du quartier. Cette structure
 * permet de connaître les feux qui lui sont attachés et sa position à l'écran
 */

typedef struct {
    int id; /*!< Identifiant du carrefour */
    int posX; /*!< Position sur l'axe X */
    int posY; /*!< Position sur l'axe Y */
    Feu tabFeux[MAX_FEU]; /*!< Tableau des structures Feu rattachées à ce carrefour */
} Carrefour;


/**
 * \typedef Carrefour * ListeCarrefours[MAX_CARREFOUR]
 * Tableau permettant de référencer toutes les structures Carrefours du quartier
 */
typedef Carrefour * ListeCarrefours[MAX_CARREFOUR];


// Initialisation et destruction d'un carrefour
Carrefour * Carrefour_init(int id, int posX, int posY);
void Carrefour_destroy(Carrefour * carrefour);

// Détection et correction des erreurs de synchronisation des feux d'un carrefour
void Carrefour_detecterErreur(Carrefour carrefour);

// Si l'ordonnancement aléatoire est choisi, cette fonction initialise la couleur des feux de manière aléatoire et corrige les erreurs de synchronisation
void Carrefour_ordoAlea(ListeCarrefours tableauCarrefours);

// Si l'ordonnancement Vague Verte est choisi, cette fonction initialise la couleur des feux de sorte à permettre une vague verte.
// Elle corrige également les erreurs de synchronisation
void Carrefour_ordoVagueVerte(Carrefour ** tableauCarrefours);

#endif // CARREFOUR_H
