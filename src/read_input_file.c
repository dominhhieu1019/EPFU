#include "read_input_file.h"

void readInputFile(int *numberOfPlayers, int *numberOfPenguins,int *playerScore, int *enemyScore,
               int playerPenguinLocation[MAXPENGUIN][2], int enemyPenguinLocation[MAXPENGUIN][2],
               int *height, int *width, int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], char *fileName, int *enemyNumber){


	int id, i, j, x, y, fish, pen;
	char nothing[10];

	FILE* fp;
	fp = fopen(fileName,"r");
    if (!fp){
		printf("File %s does not exist",fileName);
		exit(0);
		}
    rewind(fp);
    fscanf(fp,"%d;%d;\n", numberOfPlayers, numberOfPenguins);

    for (i=1; i <= (*numberOfPlayers); i++){
        fscanf(fp,"%d:",&id);
        if (id == PLAYERNUMBER){
            fscanf(fp,"%d",playerScore);
            for (j=0; j < (*numberOfPenguins); j++){
                fscanf(fp,":%d:%d",&playerPenguinLocation[j][0], &playerPenguinLocation[j][1]);
            }
        }else{
            *enemyNumber = id;
            fscanf(fp,"%d",enemyScore);
            for (j=0; j < (*numberOfPenguins); j++){
                fscanf(fp,":%d:%d",&enemyPenguinLocation[j][0], &enemyPenguinLocation[j][1]);
            }
        }
        fscanf(fp,";\n");
    }
    fscanf(fp,"%s",nothing);
    fscanf(fp,"%d:%d\n", height, width);

    while (!feof(fp)){
        fscanf(fp, "%d:%d:%d:%d\n", &x, &y, &fish, &pen);
        numFish[x][y] = fish;
        floe[x][y] = pen;
    }
    fclose(fp);
}
