CC = gcc
src = ./src
flags = -Wall -Wextra -Werror

ALL: $(src)/alpic.c
	$(CC) -o ./alpic $(src)/alpic.c $(flags)