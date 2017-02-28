#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dataNum;
    char *taxA;
    char *taxB;
    int relation;
} data;

FILE *filePointer(char fileName[], char *mode);

int main (int argc, char *argv[])
{
    FILE *filePtr = NULL;
    char fileName[255];
    int size = 0;
    char *theToken;
    int c, i, j;
    int numRows = 0;
    int numCols = 0;
    char current_char = '*';
    char to_replace = '\n';
    char replacement = ' ';
        if(argc < 2) {
            strcpy (fileName, "NO FILE INPUT");
        }
        else {
            strcpy (fileName, argv[1]);
        }
        filePtr = filePointer (fileName, "r+"); /*Call to function to find file pointer*/
        fseek (filePtr, 0, SEEK_END); //Going to the end of the file to find size
        size = ((ftell(filePtr)) + 2); //Storing the file size in variable
        rewind(filePtr); //Rewinding back to the start of the file
    char string[size];
  //      printf("Please enter the number of Rows\n"); //Asking user for the numRows to create array
    //    scanf("%d", &numRows); //Asking for COls now to create the 3Darray
   //     printf("Enter the number of Cols\n");
  //      scanf(" %d", &numCols);
        while ((current_char == fgetc(filePtr)) != EOF) {
            if(current_char == to_replace) {
                fseek(filePtr, ftell(filePtr)-1, SEEK_SET);
                fprintf(filePtr, "%c", replacement);
                printf("me here\n");
            }
        }
        fgets(string[size], size, filePtr);
        printf("%s\n", string);
/*
    char array[numRows][numCols][50]; //Creating the 3D array
        theToken = strtok(string, " ,");
        if(theToken = NULL) {
            theToken = '0';
            strcpy(array[0][0][50], theToken);
        }
        else {
            strcpy(array[0][0][50], theToken);
        }
        for(i=1; i<numRows; i++) {
            for(j=1; j<numCols; j++) {
                theToken = strtok(NULL, " ,");
                if (theToken != NULL) {
                    strcpy(array[i][j][50], theToken);
                }
                else {
                    strcpy(array[i][j][50], "0");
                }
            }
        }*/
    fclose(filePtr);
    return 0;
}

FILE *filePointer(char fileName[], char *mode)
{
    FILE *tempFile = NULL;
    char tempFile2[255];
    char tempName[255];
        strcpy(tempFile2, fileName);
        tempFile = fopen(tempFile2, mode);
        if (tempFile == NULL) {
            printf("ERROR OPENING FILE: %s\n", tempFile2);
            printf("Exiting Program\n");
        }
    return tempFile;
}
