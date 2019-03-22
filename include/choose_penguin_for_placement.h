#ifndef CHOOSE_PENGUIN_FOR_PLACEMENT_H
#define CHOOSE_PENGUIN_FOR_PLACEMENT_H

#include "define_variable.h"
#include "check_valid_move.h"
#include "check_coordinates.h"

int choosePenguinForPlacement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD],
                                int *x2, int *y2, int height, int width, int penguinToPlace);



#endif // CHOOSE_PENGUIN_FOR_PLACEMENT_H
