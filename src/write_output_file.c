#include "write_output_file.h"

void writeOutputFile(int numberOfPlayers, int numberOfPenguins,int playerScore, int enemyScore,
                     int playerPenguinLocation[MAXPENGUIN][2], int enemyPenguinLocation[MAXPENGUIN][2],
                     int height, int width, int numFish[MAXBOARD][MAXBOARD], int floe[MAXBOARD][MAXBOARD], char *fileName, int enemyNumber){

    int j;

	FILE* fp;

    fp = fopen(fileName,"w");

    fprintf(fp,"%d;%d;\n",numberOfPlayers, numberOfPenguins);

    fprintf(fp,"%d:%d",PLAYERNUMBER,playerScore);
        for (j=0; j < numberOfPenguins; j++){
            fprintf(fp,":%d:%d",playerPenguinLocation[j][0], playerPenguinLocation[j][1]);
            }
        fprintf(fp,";\n");

   fprintf(fp,"%d:%d",enemyNumber, enemyScore);
        for (j=0; j < numberOfPenguins; j++){
                fprintf(fp,":%d:%d",enemyPenguinLocation[j][0], enemyPenguinLocation[j][1]);
            }
        fprintf(fp,";\n");

    fprintf(fp,"%s","Map\n");
    fprintf(fp,"%d:%d\n", height, width);
    int x, y ;
    for(x=0; x<=height; x++){
        if (x%2 == 0){
            for (y=0; y<=width; y = y+2){
                fprintf(fp, "%d:%d:%d:%d\n", x, y, numFish[x][y], floe[x][y]);
            }
        }else{
            for (y=1; y<=width; y = y+2){
                fprintf(fp, "%d:%d:%d:%d\n", x, y, numFish[x][y], floe[x][y]);
           }
        }
    }
    fclose(fp);
}
