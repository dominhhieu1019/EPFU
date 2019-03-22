#include "check_human_move.h"

int checkHumanMove (int x1, int y1, int x2, int y2, int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD]){

    int dx, dy;
    // check if there is a floe or penguin on the way from (x1, y1) to (x2, y2)
    if (x1 == x2){
        if (y1>y2){
            for (dy = -2; dy >= y2 - y1; dy = dy - 2){
                if (numFish[x1][y1+dy] == 0 || floe[x1][y1+dy]!= 0)
                    return 0;
            }
        }else{
            for (dy = 2; dy <= y2 - y1; dy = dy + 2){
                if (numFish[x1][y1+dy] == 0 || floe[x1][y1+dy]!= 0)
                    return 0;
            }
        }
    }else if(x1 > x2){
        if (y1>y2){
            for (dx = -1, dy = -1; dx >= x2 - x1, dy >= y2 - y1; dx--, dy--){
                if (numFish[x1+dx][y1+dy] == 0 || floe[x1+dx][y1+dy]!= 0)
                    return 0;
            }
        }else{
            for (dx = -1, dy = 1; dx >= x2 - x1, dy <= y2 - y1; dx--, dy++){
                if (numFish[x1+dx][y1+dy] == 0 || floe[x1+dx][y1+dy]!= 0)
                    return 0;
            }
        }
    }else{
        if (y1>y2){
            for (dx = 1, dy = -1; dx <= x2 - x1, dy >= y2 - y1; dx++, dy--){
                if (numFish[x1+dx][y1+dy] == 0 || floe[x1+dx][y1+dy]!= 0)
                    return 0;
            }
        }else{
            for (dx = 1, dy = 1; dx <= x2 - x1, dy <= y2 - y1; dx++, dy++){
                if (numFish[x1+dx][y1+dy] == 0 || floe[x1+dx][y1+dy]!= 0)
                    return 0;
            }
        }
    }

    return 1;
}
