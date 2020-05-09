#include <stdio.h>
#include <string.h>
#include "struct.h"

int checkWord(FILE * filePointer, logic l, char * word){
    int currentState = 0;
    int currentPos = 0;
    int wordSize = strlen(word);
    for(int i = 0; i < wordSize; i++){
        currentState++;
        currentPos++;
        printf("%s", l.alphabet);
    }



    fgetc(filePointer);
    return 0;
}

void changeState(){

}