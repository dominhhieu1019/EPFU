#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "place_penguin.h"
#include "move_penguin.h"
#include "read_input_file.h"
#include "write_output_file.h"
#include "update_player_penguin_location.h"
#include "choose_penguin_for_placement.h"
#include "choose_penguin_for_movement.h"
#include "human_placement.h"
#include "human_movement.h"

int main(int argc, char*argv[]){

    int numFish[MAXBOARD][MAXBOARD] = {0};
	int floe[MAXBOARD][MAXBOARD] = {0};
	int playerScore = 0, enemyScore = 0;
	int numberOfPlayers = 0, numberOfPenguins = 0;
	int playerPenguinLocation[MAXPENGUIN][2];
	int enemyPenguinLocation[MAXPENGUIN][2] ;
	int x1=-1, y1=-1, x2=0, y2=0, height, width;
	int enemyNumber = 0;
    int penguinToPlace = 0;

    char inputFile[50];
    char outputFile[50];

    if (argv[1][6] == 'p'){
        strcpy (inputFile, argv[3]);
        strcpy (outputFile, argv[4]);
    }else{
        strcpy (inputFile, argv[2]);
        strcpy (outputFile, argv[3]);
    }

	readInputFile(&numberOfPlayers, &numberOfPenguins,&playerScore, &enemyScore,
               playerPenguinLocation, enemyPenguinLocation, &height, &width, numFish, floe, inputFile, &enemyNumber);

    if(AUTO){ //automatic mode
            if (playerScore < numberOfPenguins){
                x1 = y1 = 0;
                penguinToPlace = (int) argv[2][9] - '0';
                if (choosePenguinForPlacement(numFish, floe, &x2, &y2, height, width, penguinToPlace))
                    placePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x2, y2);
            }else{
                if (choosePenguinForMovement(numFish, floe, playerPenguinLocation, &x1, &y1, &x2, &y2, height, width, numberOfPenguins))
                    movePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x1, y1, x2, y2);
            }
            updatePlayerPenguinLocation(x1, y1, x2, y2, numberOfPenguins, playerPenguinLocation);

            writeOutputFile(numberOfPlayers, numberOfPenguins, playerScore, enemyScore,
                    playerPenguinLocation, enemyPenguinLocation, height, width, numFish, floe, outputFile, enemyNumber);

    }else if(INTERACTIVE){ //interactive move
        int p=1; // check if at least one player can move penguin
        int p1, p2;
        while (p){
            //player 1
            if (playerScore < numberOfPenguins){
                humanPlacement (numFish, floe, &x2, &y2, height, width, PLAYERNUMBER);
                placePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x2, y2);
            }else{
                if (p1 = humanMovement (numFish, floe, PLAYERNUMBER, &x1, &y1, &x2, &y2, height, width))/* x1,y1 are coordinates of a penguin user wants to move, x2,y2 are target coordinates*/
                    movePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x1, y1, x2, y2);
            }

            //player 2
            if (enemyScore < numberOfPenguins){
                humanPlacement (numFish, floe, &x2, &y2, height, width, enemyNumber);
                placePenguin(numFish, floe, enemyNumber, &enemyScore, x2, y2);
            }else{
                if (p2 = humanMovement (numFish, floe, enemyNumber, &x1, &y1, &x2, &y2, height, width))/* x1,y1 are coordinates of a penguin user wants to move, x2,y2 are target coordinates*/
                    movePenguin(numFish, floe, enemyNumber, &enemyScore, x1, y1, x2, y2);
            }
            p = p1 + p2;
        }

        //announce result
        if (playerScore > enemyScore)
            printf ("Player %d win\n", PLAYERNUMBER);
        else if (playerScore < enemyScore)
            printf ("Player %d win\n", enemyNumber);
        else
            printf ("Draw");

        return 0;

    }else{ //human vs machine
        int p=1; // check if at least one player can move penguin
        int p1, p2;
        while (p){
            //human
            if (playerScore < numberOfPenguins){
                humanPlacement (numFish, floe, &x2, &y2, height, width, PLAYERNUMBER);
                placePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x2, y2);
            }else{
                if (p1 = humanMovement (numFish, floe, PLAYERNUMBER, &x1, &y1, &x2, &y2, height, width))/* x1,y1 are coordinates of a penguin user wants to move, x2,y2 are target coordinates*/
                    movePenguin(numFish, floe, PLAYERNUMBER, &playerScore, x1, y1, x2, y2);
            }

            //machine
            if (enemyScore < numberOfPenguins){
                x1 = y1 = 0;
                penguinToPlace++;
                if (choosePenguinForPlacement(numFish, floe, &x2, &y2, height, width, penguinToPlace))
                    placePenguin(numFish, floe, enemyNumber, &enemyScore, x2, y2);
            }else{
                if (p2 = choosePenguinForMovement(numFish, floe, enemyPenguinLocation, &x1, &y1, &x2, &y2, height, width, numberOfPenguins))
                    movePenguin(numFish, floe, enemyNumber, &enemyScore, x1, y1, x2, y2);
            }
			updatePlayerPenguinLocation(x1, y1, x2, y2, numberOfPenguins, enemyPenguinLocation);

			p = p1 + p2;
        }

        //announce result
        if (playerScore > enemyScore)
            printf ("Human win\n");
        else if (playerScore < enemyScore)
            printf ("Machine win");
        else
            printf ("Draw");

        return 0;
    }


	return 0;
}

