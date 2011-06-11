#ifndef FEU_H
#define FEU_H

/**
 * \struct Feu
 * \brief Structure représentant un feu bicolore
 */
typedef struct {
    int isVert; /*!< Couleur du feu : si feu vert = 1; si feu rouge = 0 */
    int tempo; /*!< Durée entre deux changements (représente en réalité le nombre de boucles que SDL doit effectuer avant de changer la couleur) */
    int tempoCourant; /*!< Nombre de boucles effectuées par la SDL depuis le dernier changement de couleur */
    int posX; /*!< Position sur l'axe X */
    int posY; /*!< Position sur l'axe Y */
} Feu;


// Initialisation et destruction
Feu * Feu_create(void);
void Feu_destroy(Feu * feu);


// Initialisation de la couleur d'un feu
// Ordonnancement aléatoire
void Feu_initCouleurFeuAlea(Feu feu);

// Ordonnancement Vague Verte
void Feu_initCouleurRougeVagueVerte(Feu feu);

// Changement de couleur d'un feu
void Feu_changerCouleurFeu(Feu feu);
void Feu_changerCouleurFinTempo(Feu feu);


#endif // FEU_H
