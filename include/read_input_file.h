#ifndef READ_INPUT_FILE_H
#define READ_INPUT_FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "define_variable.h"

void readInputFile(int *numberOfPlayers, int *numberOfPenguins,int *playerScore, int *enemyScore,
               int playerPenguinLocation[MAXPENGUIN][2], int enemyPenguinLocation[MAXPENGUIN][2],
               int *height, int *width, int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], char *fileName, int *enemyNumber);

#endif // READ_INPUT_FILE_H
