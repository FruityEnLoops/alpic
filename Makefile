CC = gcc
src = ./src
flags = -Wall -Wextra -Werror

ALL: $(src)/alpic.o $(src)/fileChecker.o
	$(CC) -o ./alpic $(src)/*.o $(flags)

alpic.o: $(src)/alpic.c $(src)/fileChecker.o $(src)/fileChecker.h
	$(CC) -c -o $(src)/alpic.o alpic.c fileChecker.o $(flags)

fileChecker.o: $(src)/fileChecker.c $(src)/fileChecker.h
	$(CC) -c -o $(src)/fileChecker.o fileChecker.c $(flags)