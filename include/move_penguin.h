#ifndef MOVE_PENGUIN_H
#define MOVE_PENGUIN_H
#include "define_variable.h"
#include "check_valid_move.h"
#include "check_coordinates.h"

void movePenguin (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber, int *playerScore,
                  int x1, int y1, int x2, int y2);

#endif // MOVE_PENGUIN_H
