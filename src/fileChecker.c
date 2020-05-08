#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 256

// compte le nombre de ligne du fichier
int countLines(FILE * filePointer){
    int count = 0;
    char * stringBuffer = (char *) malloc( MAX_LENGTH );
    while(!feof(filePointer)){
        fgets(stringBuffer, MAX_LENGTH, filePointer);
        count++;
    }
    free(stringBuffer);
    rewind(filePointer);
    return count;
}

// vérification du fichier : chaque état a son délimiteur sur chaque ligne
int checkStates(FILE * filePointer){
    char delim = ';';
    char * stringBuffer = (char *) malloc(MAX_LENGTH);
    int cpt = 0;

    // passage des 3 premières lignes (headers)
    for(int i = 0; i < 3; i++){
        fgets(stringBuffer, MAX_LENGTH, filePointer);
    }
    int j;
    for(int i = 0; i < 5; i++){
        fgets(stringBuffer, MAX_LENGTH, filePointer);
        j = 0;
        while(stringBuffer[j] != '\0'){
            if(stringBuffer[j] == delim){
                cpt++;
            }
            j++;
        }
    }

    free(stringBuffer);
    rewind(filePointer);
    if(cpt == 20){
        return 0;
    } else {
        return 1;
    }
}

// renvoi 1 ou 0 selon la validité du fichier
int checkFile(FILE * filePointer){
    int lineCount = countLines(filePointer);
    int stateCheck = checkStates(filePointer);
    if(lineCount == 8 && stateCheck == 0){
        return 0;
    } else {
        return 1;
    }
}

