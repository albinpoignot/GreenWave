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
Voiture * Voiture_create();
void Voiture_destroy(Voiture *voiture);

// Déplacement
void Voiture_deplacer(Voiture *voiture);
void Voiture_deplacementVertical(Voiture *voiture, Voiture *voitureDevant);
void Voiture_deplacementHorizontal(Voiture *voiture, Voiture *voitureDevant);
void Voiture_bouger(Voiture *voiture);

// Fonction intermédiaire
int Voiture_definirIndiceCarrefourDest(int depart, int arrivee);
int Voiture_trouverIndiceVoitureDansFile(Voiture *voiture);
