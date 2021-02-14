# -*-Makefile -*-
CC=g++
OPTS=-g -Wall
OBJS=game_entry.o score.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

score.o: ./score.cpp 
	$(CC) $(OPTS) -c ./score.cpp

game_entry.o: ./game_entry.cpp
	$(CC) $(OPTS) -c ./game_entry.cpp

clean:
	rm -rf *.o *.dSYM main