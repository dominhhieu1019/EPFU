#ifndef HUMAN_MOVEMENT_H
#define HUMAN_MOVEMENT_H

#include "define_variable.h"
#include <windows.h>
#include "check_coordinates.h"
#include "check_valid_move.h"
#include "check_human_move.h"

int humanMovement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber,
                    int *x1, int *y1, int *x2, int *y2, int height, int width);


#endif // HUMAN_MOVEMENT_H
