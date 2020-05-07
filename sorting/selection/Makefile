# -*-Makefile -*-
CC=gcc
OPTS=-g -std=gnu99 -Wall
OBJS=selection_sort.o
OBJ_FOLDER=./obj
BIN_FOLDER=./bin



./bin/main: ./main.c $(OBJS)
	$(CC) $(OPTS) -o ./bin/main main.c $(OBJS)

selection_sort.o: ./lib/selection_sort.c
	$(CC) $(OPTS) -c ./lib/selection_sort.c

clean:
	rm -rf *.o
	rm -rf $(BIN_FOLDER)/*