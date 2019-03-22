#include "human_movement.h"

int humanMovement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int playerNumber,
                    int *x1, int *y1, int *x2, int *y2, int height, int width){
                     int i=0;
                    do{
                        system("cls");
                        printf("Player %d\n", playerNumber);
                        printf("Movement\n");
                        if (i>0){
                            printf ("Type 1 if you can move penguin. If not, type 0: ");
                            int c;
                            scanf("%d", &c);
                            if (c==0)
                                return 0;
                        }
                        printf ("\nPenguin coordinate: \n");
                        printf("x: ");
                        scanf("%d", x1);
                        printf("\ny: ");
                        scanf("%d", y1);
                        printf ("Target coordinate:\n");
                        printf("x: ");
                        scanf("%d", x2);
                        printf("\ny: ");
                        scanf("%d", y2);
                        i++;

                    }while (!(checkValidMove(*x1, *y1, *x2, *y2) && checkCoordinates(*x2,*y2,height,width) && numFish[*x2][*y2] != 0
                              && floe [*x1][*y1] == playerNumber && floe[*x2][*y2] == 0 && checkHumanMove(*x1, *x2, *y1, *y2, numFish, floe)));
                    return 1;
}

