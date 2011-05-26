// Initialisation et destruction d'une voiture
/**
 * \fn Voiture * Voiture_create()
 * \brief Alloue une correctement une structure Voiture et la retourne
 *
 * \return La structure Voiture nouvellement allouée
 */
Voiture * Voiture_create();

/**
 * \fn void Voiture_destroy(Voiture *voiture);
 * \brief Libère la mémoire utilisée par la structure Voiture en paramêtre
 *
 * \param voiture La voiture à libérer
 */
void Voiture_destroy(Voiture *voiture);

// Déplacement
void Voiture_deplacer(Voiture *voiture);
void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant);
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant);
void Voiture_bouger(Voiture *voiture);

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee);
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture);
