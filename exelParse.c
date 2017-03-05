#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *filePointer(char fileName[], char *mode);

int main (int argc, char *argv[])
{
    FILE *filePtr = NULL;
    char fileName[255];
    int size = 0;
    char *theToken;
    int i, j, k;
    k = 0;
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
        printf("Please enter the number of Rows\n"); //Asking user for the numRows to create array
        scanf("%d", &numRows); //Asking for COls now to create the 3Darray
        printf("Enter the number of Cols\n");
        scanf(" %d", &numCols);
        while ((current_char = fgetc(filePtr)) != EOF) {
            if(current_char == to_replace) {
                fseek(filePtr, ftell(filePtr)-1, SEEK_SET);
                fprintf(filePtr, "%c", replacement);
            }
        }
        fseek(filePtr, -2, SEEK_END); //Insert the newline char at the end again.
        fprintf(filePtr, "%c", to_replace);
        rewind(filePtr); //Go back to the start of the stream
        fgets(string, size, filePtr);
//        printf("%s\n", string);
          /*It works up till here*/

    char array[numRows][numCols][50]; //Creating the 3D array
        theToken = strtok(string, ",");
        strcpy(array[0][0], theToken);
        while (theToken != NULL) {
            for(i=0; i < (numRows + 1); i++) {
                for(j=1; j < (numCols + 1); j++) {
                    theToken = strtok(NULL, ",");
                    strcpy(array[i][j], theToken);
                   // printf("%s %d %d\n", array[i][j], i, j);
                   k++;
                }
            }
        }
        printf("*******************%d****************", k);
/*
        for(i=0; i<numRows; i++) { //This should print the array
            for(j=0; j<numCols; j++) {
                printf("%s ", array[i][j]);
            }
        }
*/
    fclose(filePtr);
    return 0;
}

FILE *filePointer(char fileName[], char *mode)
{
    FILE *tempFile = NULL;
    char tempFile2[255];
        strcpy(tempFile2, fileName);
        tempFile = fopen(tempFile2, mode);
        if (tempFile == NULL) {
            printf("ERROR OPENING FILE: %s\n", tempFile2);
            printf("Exiting Program\n");
        }
    return tempFile;
}
