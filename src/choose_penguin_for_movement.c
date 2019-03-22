#include "choose_penguin_for_movement.h"

int choosePenguinForMovement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerPenguinLocation[MAXPENGUIN][2],
                               int *x1, int *y1, int *x2, int *y2, int height, int width, int numberOfPenguins){

            int i, xPen, yPen, distance = INT_MAX, maxFish=-1;
                for (i=0; i<numberOfPenguins; i++){
                    xPen = playerPenguinLocation[i][0];
                    yPen = playerPenguinLocation[i][1];
                    int dx,dy;

                    //check moves horizontally right
                    for (dy = 2; dy <= width - yPen; dy = dy+2){
                        if (numFish[xPen][yPen+dy]==0 || floe[xPen][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen][yPen+dy] && fabs(dy/2) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen][yPen+dy];
                            distance = fabs(dy/2);
                            continue;
                        }
                        if (maxFish < numFish[xPen][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen][yPen+dy];
                        }
                    }

                    //check moves horizontally left
                    for (dy = -2; dy >= -yPen; dy = dy-2){
                        if (numFish[xPen][yPen+dy]==0 || floe[xPen][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen][yPen+dy] && fabs(dy/2) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen][yPen+dy];
                            distance = fabs(dy/2);
                            continue;
                        }
                        if (maxFish < numFish[xPen][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen][yPen+dy];
                        }
                    }

                    //check moves north-east
                    for (dx = -1, dy = 1; dx >= -xPen, dy <= width - yPen; dx--, dy++){
                        if (numFish[xPen+dx][yPen+dy]==0 || floe[xPen+dx][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen+dx][yPen+dy] && fabs(dy) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                            distance = fabs(dy);
                            continue;
                        }
                        if (maxFish < numFish[xPen+dx][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                        }
                    }

                    //check moves north-west
                    for (dx = -1, dy = -1; dx >= -xPen, dy >= -yPen; dx--, dy--){
                        if (numFish[xPen+dx][yPen+dy]==0 || floe[xPen+dx][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen+dx][yPen+dy] && fabs(dy) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                            distance = fabs(dy);
                            continue;
                        }
                        if (maxFish < numFish[xPen+dx][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                        }
                    }

                    //check moves south-west
                    for (dx = 1, dy = -1; dx <= height - xPen, dy >= -yPen; dx++, dy--){
                        if (numFish[xPen+dx][yPen+dy]==0 || floe[xPen+dx][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen+dx][yPen+dy] && fabs(dy) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            distance = fabs(dy);
                            maxFish = numFish[xPen+dx][yPen+dy];
                            continue;
                        }
                        if (maxFish < numFish[xPen+dx][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                        }
                    }

                    //check moves south-east
                    for (dx = 1, dy = 1; dx <= height - xPen, dy <= width - yPen; dx++, dy++){
                        if (numFish[xPen+dx][yPen+dy]==0 || floe[xPen+dx][yPen+dy]!=0) break;
                        if (maxFish <= numFish[xPen+dx][yPen+dy] && fabs(dy) < distance){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                            distance = fabs(dy);
                            continue;
                        }
                        if (maxFish < numFish[xPen+dx][yPen+dy]){
                            *x1 = xPen;
                            *y1 = yPen;
                            *x2 = xPen + dx;
                            *y2 = yPen + dy;
                            maxFish = numFish[xPen+dx][yPen+dy];
                        }
                    }
                }

                if (maxFish < 0){
                    printf("Cannot move\n");
                    return 0;
                }
                return 1;
}
