# -*-Makefile -*-
CC=g++
OPTS=-g -Wall
OBJS=triangle.o circle.o rectangle.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

triangle.o: ./triangle.cpp
	$(CC) $(OPTS) -c ./triangle.cpp

circle.o: ./circle.cpp
	$(CC) $(OPTS) -c ./circle.cpp

rectangle.o: ./rectangle.cpp
	$(CC) $(OPTS) -c ./rectangle.cpp

clean:
	rm -rf *.o *.dSYM main