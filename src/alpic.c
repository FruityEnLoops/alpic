#include <stdio.h>
#include <string.h>
#include "fileChecker.h"
#include "logic.h"

void printLine(FILE * filePointer){
    char ch;
    do {
        ch = fgetc(filePointer);
        putchar(ch);
    } while(ch != '\n');
}

char * printState(FILE * filePointer){
    char spc = ' ';
    char sep = '|';
    char * etat = "";
    for(int i = 0; i < 4; i++){
        char ch;
        int j = 0;
        do{
            ch = fgetc(filePointer);
            strncat(etat, &ch, 1);
            j++;
        } while(ch != ';');
        for(int k = 5 - j; k < 5; k++){
            strncat(etat, spc, 1);
        }
        strncat(etat, sep, 1);
    }
    return etat;
}

// note : nécéssite que le filePointer soit déjà sur la ligne 4
void printTransitions(FILE * filePointer){
    printf("  |  0  |  1  |  2  |  3  |  4  |  5");
    printf("0 | %s", printState(filePointer));
    printf("1 | %s", printState(filePointer));
    printf("2 | %s", printState(filePointer));
    printf("3 | %s", printState(filePointer));
    printf("4 | %s", printState(filePointer));
    printf("5 | %s", printState(filePointer));
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
}

int main(int argc, char** argv){
    if(argc > 3){
        printf("Error : trop d'arguments\n");
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    }
    if(argc < 3){
        printf("Erreur : arguments requis\n");
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    }
    FILE * filePointer;
    filePointer = fopen(argv[1], "r"); // ouvre le fichier en lecture seule, aucun besoin d'écrire
    if(filePointer == NULL){
        printf("Erreur : nom de fichier incorrect ou impossible d'ouvrir %s (problème de permission de lecture?)\n", argv[1]);
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    }

    printLogicInfo(filePointer);
    rewind(filePointer); // on ne peut pas rewind dans une fonction

    int errorlevel = checkFile(filePointer);
    if(errorlevel != 0){
        printf("There was an error parsing the file. Make sure the file is correct.");
        return 1;
    }

    fclose(filePointer);
    return 0;
}