#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "alpic.h"
#define MAX_STRING_LENGTH 256

// checks if a string contains the passed char, return 1 if true, 0 if false
int containsString(char c, char* s){
    if(strchr(s, c) == NULL){
        return 0;
    } else {
        return 1;
    }
}

// checks if a state contains the passed char, return state number if true, 5 if false
int contains(char c, char** state){
    for(int i = 0; i < 5; i++){
        if(containsString(c, state[i])){
            return i;
        }
    }
    return 5;
}

int checkWord(FILE * filePointer, logic l, char * word){
    int currentState = 0;
    
    int wordSize = strlen(word);

    char buffer[MAX_STRING_LENGTH] = "";
    for(int i = 0; i < 3; i++){
        fgets(buffer, MAX_STRING_LENGTH, filePointer);
    }
    char** *states[5];
    char** state0 = split(fgets(buffer, MAX_STRING_LENGTH, filePointer),';');
    states[0] = &state0;
    char** state1 = split(fgets(buffer, MAX_STRING_LENGTH, filePointer),';');
    states[1] = &state1;
    char** state2 = split(fgets(buffer, MAX_STRING_LENGTH, filePointer),';');
    states[2] = &state2;
    char** state3 = split(fgets(buffer, MAX_STRING_LENGTH, filePointer),';');
    states[3] = &state3;
    char** state4 = split(fgets(buffer, MAX_STRING_LENGTH, filePointer),';');
    states[4] = &state4;
    
    rewind(filePointer);

    int possibleChange;
    for(int i = 0; i < wordSize; i++){
        possibleChange = contains(word[i], *states[currentState]);
        if(possibleChange != 5){
            currentState = possibleChange;
        } else {
            return 1;
        }
    }

    printf("%s", l.alphabet);
    fgetc(filePointer);
    if(containsString(currentState, l.etatAcceptant) == 1){
        return 0;
    } else {
        return 1;
    }
}