# -*-Makefile -*-
CC=g++
OPTS=-g -Wall
OBJS=basic_vector.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

basic_vector.o: ./basic_vector.cpp
	$(CC) $(OPTS) -c ./basic_vector.cpp

clean:
	rm -rf *.o *.dSYM main