#ifndef PLACE_PENGUIN_H
#define PLACE_PENGUIN_H
#include "define_variable.h"
#include "check_valid_move.h"
#include "check_coordinates.h"

void placePenguin (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber, int *playerScore,
                   int x2, int y2);

#endif // PLACE_PENGUIN_H
