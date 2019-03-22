#include "update_player_penguin_location.h"

void updatePlayerPenguinLocation(int x1, int y1, int x2, int y2, int numberOfPenguins, int playerPenguinLocation[MAXPENGUIN][2]){
    int i;
    for (i=0; i<numberOfPenguins; i++){
        if (playerPenguinLocation[i][0] == x1 && playerPenguinLocation[i][1] == y1){
            playerPenguinLocation[i][0] = x2;
            playerPenguinLocation[i][1] = y2;
            return;
        }
    }
}
