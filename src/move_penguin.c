#include "move_penguin.h"

void movePenguin (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber, int *playerScore,
                  int x1, int y1, int x2, int y2){

        *playerScore += numFish[x2][y2];
        numFish[x2][y2] = 0;
        floe[x2][y2]= playerNumber;
        floe[x1][y1] = 0;

}
