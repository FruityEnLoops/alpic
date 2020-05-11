#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "alpic.h"

#define MAX_STRING_LENGTH 256

// vérifie si un string contient un char (et renvoi 1 pour true et 0 pour false, strchr renvoyant un pointer)
int containsString(char c, char* s){
    if(strchr(s, c) == NULL){
        return 0;
    } else {
        return 1;
    }
}

// vérifie que l'etat contiens le char, renvoi le numéro de l'etat si trouvé, sinon 5
int contains(char c, char** state){
    for(int i = 0; i < 5; i++){
        if(containsString(c, state[i])){
            return i;
        }
    }
    return 5;
}

int checkWord(FILE * filePointer, logic l, char * word){
    int currentState;
    if ('0' <= l.etatInitial && l.etatInitial <= '9') {
        currentState = (char) l.etatInitial - '0';
    } else { 
        return 1;
    }

    int returnVal = 0;
    
    int wordSize = strlen(word);

    char buffer[MAX_STRING_LENGTH] = "";
    rewind(filePointer);
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
            returnVal = 1;
            break;
        }
    }

    // libère les mallocs créés par split()
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            free((*(states[i]))[j]);
        }
        free(*states[i]);
    }

    if(containsString(currentState, l.etatAcceptant) == 1 && returnVal == 0){
        return 0;
    } else {
        return 1;
    }
}