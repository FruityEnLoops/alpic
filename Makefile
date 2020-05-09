CC = gcc
src = ./src
CFLAGS = -g -Wall -Wextra -Werror

ALL: $(src)/alpic.o $(src)/fileChecker.o $(src)/logic.o $(src)/struct.o
	$(CC) -o ./alpic $(src)/*.o $(CFLAGS)

alpic.o: $(src)/alpic.c $(src)/fileChecker.o $(src)/fileChecker.h
	$(CC) -c -o $(src)/alpic.o alpic.c fileChecker.o $(CFLAGS)

fileChecker.o: $(src)/fileChecker.c
	$(CC) -c -o $(src)/fileChecker.o fileChecker.c $(CFLAGS)

logic.o: $(src)/logic.c $(src)/logic.h
	$(CC) -c -o $(src)/logic.o logic.c $(CFLAGS)

struct.o: $(src)/struct.c $(src)/struct.h
	$(CC) -c -o $(src)/struct.o struct.c $(CFLAGS)

clean: 
	rm $(src)/*.o