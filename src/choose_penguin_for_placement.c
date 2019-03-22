#include "choose_penguin_for_placement.h"

int choosePenguinForPlacement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD],
                                int *x2, int *y2, int height, int width, int penguinToPlace){

                                    int x,y;
                                    if (penguinToPlace % 2 != 0 && penguinToPlace % 3 != 0){
                                        for (x = 0; x<=height; x++){
                                            if (x % 2 == 0){
                                                for (y = 0; y <= width; y = y+2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }else{
                                                for (y = 1; y <= width; y = y+2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }else if (penguinToPlace % 2 == 0 && penguinToPlace % 4 != 0 && penguinToPlace % 3 != 0){
                                        for (x = height; x >= 0; x--){
                                            if (x % 2 == 0){
                                                if (width % 2 == 0){
                                                    y = width;
                                                }else{
                                                    y = width - 1;
                                                }
                                                for (y; y >= 0; y = y-2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }else{
                                                if (width % 2 != 0){
                                                    y = width;
                                                }else{
                                                    y = width - 1;
                                                }
                                                for (y; y >= 0; y = y-2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }else if (penguinToPlace % 3 == 0){
                                        for (x = height; x >= 0; x--){
                                            if (x % 2 == 0){
                                                for (y = 0; y <= width; y = y+2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }else{
                                                for (y = 1; y <= width; y = y+2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }else{
                                        for (x = 0; x <= height; x--){
                                            if (x % 2 == 0){
                                                if (width % 2 == 0){
                                                    y = width;
                                                }else{
                                                    y = width - 1;
                                                }
                                                for (y; y >= 0; y = y-2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }else{
                                                if (width % 2 != 0){
                                                    y = width;
                                                }else{
                                                    y = width - 1;
                                                }
                                                for (y; y >= 0; y = y-2){
                                                    if(numFish[x][y] == 1 && floe[x][y] == 0){
                                                        *x2 = x;
                                                        *y2 = y;
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    printf("Cannot place penguin!");
                                    return 0;


}
