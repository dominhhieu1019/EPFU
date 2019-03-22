#include "place_penguin.h"

void placePenguin (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber, int *playerScore,
                   int x2, int y2){

        *playerScore += numFish[x2][y2];
        floe[x2][y2] = playerNumber;
        numFish[x2][y2] = 0;
}
