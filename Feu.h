typedef struct {
    int isVert; //feu vert = 1; feu rouge = 0
    int tempo;
    int posX;
    int posY;
} Feu;


// Initialisation et destruction
Feu * feu_create(void);
void feu_destroy(Feu feu);


// Initialisation de la couleur d'un feu
    // Ordonnancement aléatoire
void feu_initCouleurFeuAlea(Feu feu);

    // Ordonnancement Vague Verte
void feu_initCouleurRougeVagueVerte(Feu feu);

// Changement de couleur d'un feu
void feu_changerCouleurFeu(Feu feu);
void feu_changerCouleurFinTempo(Feu feu);

// Temporisation
void feu_temporisation (Feu feu); //Trouver paramètres ou si suppressions
