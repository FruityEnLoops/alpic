#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileChecker.h"
#include "struct.h"
#include "logic.h"

#define MAX_STRING_LENGTH 256
#define MAX_LENGTH 5

void printLine(FILE * filePointer){
    char ch;
    do {
        ch = fgetc(filePointer);
        putchar(ch);
    } while(ch != '\n');
}

char** split(char * s, char delim){
    char ch;
    int incr = 0;
    char** states = malloc(MAX_LENGTH * sizeof(void *));
    int stateSize = 0;
    for(int i = 0; i < 5; i++){
        states[i] = NULL; // on ne peut pas concatener avec rien, donc strncat va initialiser states[i] avec un endroit de la RAM si on ne le met pas a NULL
        stateSize = 0;
        do{
            ch = s[incr];
            states[i] = realloc(states[i], incr + 4 * sizeof(char));
            states[i][stateSize] = '\0'; // on affecte un \0 pour que strncat ne donne pas d'erreur et sache ou concatener ch
            states[i] = strncat(states[i], &ch, 1);
            incr++;
            stateSize++;
        } while(s[incr - 1] != delim && s[incr - 1] != '\0');
        states[i][stateSize] = '\0';
    }
    if(strlen(states[4]) > 0){
        states[4][strlen(states[4]) - 2] = '\0';
    }
    return states;
}

void printState(FILE * filePointer){
    char buffer[MAX_STRING_LENGTH] = "";
    fgets(buffer, MAX_STRING_LENGTH, filePointer);
    char** splitted = split(buffer, ';');
    for(int i = 0; i < 5; i++){
        printf("%-5s|", splitted[i]);
        free(splitted[i]);
    }
    free(splitted);
}

// note : nécéssite que le filePointer soit déjà sur la ligne 4
void printTransitions(FILE * filePointer){
    printf("  |  0  |  1  |  2  |  3  |  4  |");
    printf("\n0 |");
    printState(filePointer);
    printf("\n1 |");
    printState(filePointer);
    printf("\n2 |");
    printState(filePointer);
    printf("\n3 |");
    printState(filePointer);
    printf("\n4 |");
    printState(filePointer);
    printf("\n");
}

void printLogicInfo(FILE * filePointer){
    printf("Description de l'automate :\n\n");
    printf("Alphabet : ");
    printLine(filePointer);
    printf("Etats initial(aux) : ");
    printLine(filePointer);
    printf("Etats final(aux) : ");
    printLine(filePointer);
    printf("Transition :\n");
    printTransitions(filePointer);
    rewind(filePointer);
}

int main(int argc, char** argv){
    if(argc > 3){
        printf("✘ Erreur : trop d'arguments\n");
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    }
    if(argc < 3){
        printf("✘ Erreur : arguments requis\n");
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    }
    FILE * filePointer = fopen(argv[1], "r"); // ouvre le fichier en lecture seule, aucun besoin d'écrire;
    if(filePointer == NULL){
        printf("✘ Erreur : nom de fichier incorrect ou impossible d'ouvrir '%s' (problème de permission de lecture?)\n", argv[1]);
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        fclose(filePointer);
        return 1;
    }

    int errorlevel = checkFile(filePointer);
    if(errorlevel != 0){
        printf("Ce fichier n'est pas accepté. Vérifiez que le fichier est correct.\n");
        fclose(filePointer);
        return 1;
    }

    printLogicInfo(filePointer);
    printf("\n");
    logic l = createLogic(filePointer);

    if(checkWord(filePointer, l, argv[2]) == 0){
        printf("\033[32;01m✓ Mot accepté!\033[00m\n\n");
    } else {
        printf("\033[31;01m✘ Mot refusé!\033[00m\n\n");
    }
    fclose(filePointer);
    return 0;
}