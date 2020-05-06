#include <stdio.h>
#include "fileChecker.h"

int main(int argc, char** argv){
    if(argc > 3){
        printf("Error : too much arguments\n");
        printf("Correct usage : alpic <filename> <phrase to check>\n");
        return 1;
    } else if(argc < 2){
        printf("Error : not enough arguments\n");
        printf("Correct usage : alpic <filename> <phrase to check>\n");
        return 1;
    }
    FILE * filePointer;
    filePointer = fopen(argv[1], "r"); // opens file in read only mode, write isn't needed
    if(filePointer == NULL){
        printf("Error : incorrect filename or failed to open file %s (maybe check your read privilegies?)\n", argv[1]);
        printf("Correct usage : alpic <filename> <phrase to check>\n");
        return 1;
    }

    char ch;
    do 
    {
        ch = fgetc(filePointer);
        putchar(ch);
    } while(ch != EOF);
    printf("\n"); // prints missing newline from end of file
    
    rewind(filePointer);

    printf("check result : %d\n", checkFile(filePointer));

    printf("Everything looks fine!\n");
    // when program is done
    fclose(filePointer);
    return 0;
}