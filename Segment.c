/**
 * \file Segment.c
 * \brief Module Segment
 * \author Albin POIGNOT, Mélanie MAUGEAIS
 * \version 0.1
 */

#include <stdio.h>
#include <stdlib.h>

#include "Segment.h"

/**
 * \fn Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour2)
 * \brief Alloue une structure Segment sur le tas et initialise les deux Carrefours qui le délimite
 *
 * \param carrefour1 Carrefour au début du Segement
 * \param carrefour2 Carrefour à la fin du Segment
 *
 * \return Pointeur sur le Segement nouvellement alloué
 */
Segment * Segment_init(Carrefour * carrefour1, Carrefour * carrefour2)
{
    Segment * seg = NULL;
    seg = (Segment *)malloc(sizeof(Segment));

    seg->carrefourEntree = carrefour1;
    seg->carrefourSortie = carrefour2;

    return seg;
}

/**
 * \fn void Segment_destroy(Segment * seg)
 * \brief Libère une structure Segment allouée sur le tas
 *
 * \param seg Structure Segement à libérer
 */
void Segment_destroy(Segment * seg)
{
    free(seg);
}
