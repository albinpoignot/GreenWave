#include <stdio.h>
#include <stdlib.h>

#include "Segment.h"

Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour4)
{
    Segment * seg = NULL;
    seg = (Segment *)malloc(sizeof(Segment));

    return seg;
}
