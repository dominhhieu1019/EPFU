#include "human_placement.h"

void humanPlacement (int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], int *x2, int *y2, int height, int width, int playerNumber){
                     int i = 0;
                    do{
                        system("cls");
                        if (i>0){
                            printf ("WRONG COORDINATE!\n DO AGAIN!");
                        }
                        printf("Player %d\n", playerNumber);
                        printf("Placement\n");
                        printf ("Target coordinate:\n");
                        printf("x: ");
                        scanf("%d", x2);
                        printf("\ny: ");
                        scanf("%d", y2);
                        i++;
                    }while (!(checkCoordinates(*x2,*y2,height,width) && numFish[*x2][*y2] == 1 && floe[*x2][*y2] == 0));
}
