#include "struct.h"
#include "string.h"
#define MAX_STRING_LENGTH 256

logic createLogic(FILE * filePointer){
    logic l;
    fgets(l.alphabet, MAX_STRING_LENGTH, filePointer);
    l.etatInitial = fgetc(filePointer);
    char ch;
    do {
        ch = fgetc(filePointer);
    } while(ch != '\n');
    // passe les char jusqu'a la prochaine ligne; on limite a un seul état initial (le premier) car trop complexe a gérer pour l'instant
    fgets(l.etatAcceptant, MAX_STRING_LENGTH, filePointer);
    l.etatAcceptant[strlen(l.etatAcceptant)-1] = '\0';
    return l;
}