CC = gcc
src = ./src
flags = -Wall -Wextra -Werror

ALL: $(src)/alpic.c
	$(CC) -o alpic.o $(src)/alpic.c $(flags)