#include <stdio.h>
#include "fileChecker.h"
#include "logic.h"

void printFile(FILE * filePointer){
    printf("Content of file : \n\n");
    char ch;
    do {
        ch = fgetc(filePointer);
        putchar(ch);
    } while(ch != EOF);
    printf("\n\n");
}

int main(int argc, char** argv){
    if(argc > 3){
        printf("Error : trop d'arguments\n");
        printf("Utilisation : alpic <filename> <mot a vérifier>\n");
        return 1;
    } else if(argc < 2){
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

    printFile(filePointer);
    rewind(filePointer); // on ne peut pas le rewind dans la fonction... ?

    int errorlevel = checkFile(filePointer);
    if(errorlevel != 0){
        printf("There was an error parsing the file. Make sure the file is correct.");
        return 1;
    }

    fclose(filePointer);
    return 0;
}