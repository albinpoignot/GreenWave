#include <stdio.h>
#include <stdlib.h>

#include "Segment.h"

Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour4)
{
    Segment * seg = NULL;
    seg = (Segment *)malloc(sizeof(Segment));

    seg->carrefourEntree = carrefour1;
    seg->carrefourSortie = carrefour4;

    return seg;
}
