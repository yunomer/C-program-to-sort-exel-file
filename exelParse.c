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
    int c, i;
    char array[300][500];
    char line[10000];
    for (i=0; i < 10000; i++) {
        line [i] = '*';
    }

    if(argc < 2) {
        strcpy (fileName, "NO FILE INPUT");
    }
    else {
        strcpy (fileName, argv[1]);
    }
    filePtr = filePointer (fileName, "r"); /*Call to function to find file pointer*/
    for(i = 0; i < 300; i++) {
        fscanf(filePtr, "%s", line);
        printf("%s\n", line);
    }


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
