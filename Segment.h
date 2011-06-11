#ifndef SEGMENT_H
#define SEGMENT_H

#include "Carrefour.h"

#define MAX_CARREFOUR 21
//#include "Voiture.h" <- Est inclut plus loin dans le fichier pour permettre de faire certains typedef avant

typedef struct Segment Segment;
/**
 * \struct Segment
 * \brief Structure représentant un Segment et sa file de voitures (ATTENTION : un Segment = UN SEUL sens de circulation d'une route)
 */
struct Segment {
    Carrefour * carrefourEntree; /*!< Carrefour au début du Segment */
    Carrefour * carrefourSortie; /*!< Carrefour à la fin du Segment */
    struct File * file; /*!< File de Voitures du Segment */
};

/**
 * \typedef Carrefour * ListeCarrefours[MAX_CARREFOUR]
 * \brief Tableau permettant de référencer toutes les structures Carrefours du quartier
 */
typedef int Traces[62][7];

/**
 * \typedef Carrefour * ListeCarrefours[MAX_CARREFOUR]
 * \brief Tableau permettant de référencer toutes les structures Carrefours du quartier
 */
typedef int Chemins[21][21][7];

/**
 * \typedef Segment * ListeSegments[MAX_CARREFOUR][MAX_CARREFOUR]
 * \brief Tableau permettant de référencer tous les Segment du quartier. ListeSegments[i][j] où i est l'indice du carrefour au début du segment et j l'indice du carrefour à la fin du segment.
 */
typedef Segment * ListeSegments[MAX_CARREFOUR][MAX_CARREFOUR];


#include "Voiture.h"

/**
 * \struct File
 * \brief File de Voitures. Une file est reliée à un unique Segment.
 */
typedef struct File File;
struct File {
    int id; /*!< Identifiant de la file */
    struct Voiture * voitureAvant; /*!< Voiture précédent l'élément actuel */
    struct Voiture * voiture; /*!< Element actuel */
    struct Voiture * voitureApres; /*!< Voiture suivant l'élément actuel */
};

//Segment * listeSegments[MAX_CARREFOUR][MAX_CARREFOUR];
Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour2);
void Segment_destroy(Segment * seg);

#endif // SEGMENT_H
