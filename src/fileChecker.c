#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 256

int countLines(FILE * filePointer){
    int count;
    char * stringBuffer = (char *) malloc( MAX_LENGTH );
    while(!feof(filePointer)){
        fgets(stringBuffer, MAX_LENGTH, filePointer);
        count++;
    }
    free(stringBuffer);
    rewind(filePointer);
    return count;
}

int checkFile(FILE * filePointer){
    int lineCount = countLines(filePointer);
}

