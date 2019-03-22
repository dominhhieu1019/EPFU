#ifndef CHOOSE_PENGUIN_FOR_MOVEMENT_H
#define CHOOSE_PENGUIN_FOR_MOVEMENT_H

#include "define_variable.h"
#include <math.h>
#include <limits.h>
int choosePenguinForMovement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerPenguinLocation[MAXPENGUIN][2],
                               int *x1, int *y1, int *x2, int *y2, int height, int width, int numberOfPenguins);



#endif // CHOOSE_PENGUIN_FOR_MOVEMENT_H
