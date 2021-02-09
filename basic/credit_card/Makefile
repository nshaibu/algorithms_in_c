# -*-Makefile -*-
CC=g++
OPTS=-g -Wall
OBJS=credit_card.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

credit_card.o: ./credit_card.cpp
	$(CC) $(OPTS) -c ./credit_card.cpp

clean:
	rm -rf *.o