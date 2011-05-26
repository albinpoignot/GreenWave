#include "Structures.h"

/**
 * Segment de route (1 par sens de circulation)
 *  -> relie deux carrefours entre eux
 */
typedef struct {
    Carrefour * carrefourEntree;
    Carrefour * carrefourSortie;
    File * file;
} Segment;

Segment * listeSegments[MAX_CARREFOUR][MAX_CARREFOUR];
Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour4);

