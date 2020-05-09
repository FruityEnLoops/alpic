#include <stdio.h>
#define MAX_STRING_LENGTH 256

typedef struct{
  char etatInitial;
  char etatAcceptant[MAX_STRING_LENGTH];
  char alphabet[MAX_STRING_LENGTH];
} logic;

logic createLogic(FILE * filePointer);