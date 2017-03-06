#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *filePointer(char fileName[], char *mode);
void parseLine (char string[], char ***array, int numRows, int numCols);

int main (int argc, char *argv[])
{
    FILE *filePtr = NULL;
    char fileName[255];
    int size = 0;
    int i, j;
    int numRows = 0;
    int numCols = 0;
    char ***array = NULL;
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
        fseek(filePtr, -2, SEEK_END); //Insert the newline char at the end to input.
        fprintf(filePtr, "%c", to_replace);
        rewind(filePtr); //Go back to the start of the stream
        fgets(string, size, filePtr);
        string[strlen(string) - 1] = '\0';//removing the new line char now
        array = malloc(sizeof(char**) * numRows); //Mallocing the 3D array
        for (i=0; i < numRows; i++) {
            array[i] = malloc(sizeof(char*) * numCols);
            for (j=0; j < numCols; j++) {
                array[i][j] = malloc(sizeof(char) * 50);
            }
        }
        parseLine(string, array, numRows, numCols); //Sending the string to be put into an array
        for (i=0; i < 2; i++) {
            for (j=0; j < numCols; j++) {
                printf("%s %d %d\n", array[i][j], i, j);
            }
        }
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

void parseLine (char string[], char ***array, int numRows, int numCols)
{ //This function will parse the MEGA string and move them to the 3D array.
    int i = 0;
    int j = 0;
    int k = 0; //position in the string
    int m = 0;
    int length = strlen(string);
    //array[0][0][0] = string[0]; //Moving the 0 to array position 0 0.
        for (i = 0; i < numRows; i++) { //Now parsing the rest of the string
            for (j = 0; j < numCols; j++) {
                if(string[0] != ',') {
                    array[0][0][0] = string[0];
                    j++;
                }
                for (k = k; k < length; k++) { //This will find the position of the ',' in the string
                    if (string[k] == ',') {
                        break;
                    }
                }
                k++; //Move to the next character in the string
                for (k = k; k < length; k++) {
                    if (string[k] != ',') { //As long as the character at position k is not ',' I copy into the array position i j
                        array[i][j][m] = string[k]; //Copying char by char
                        m++;
                    }
                    else {
                        m = 0;
                        break; //The moment the index if the next comma is reached, break loop
                    }
                }
            }
        }
}
