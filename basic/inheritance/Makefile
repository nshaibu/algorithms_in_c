# -*-Makefile -*-
CC=g++
OPTS=-g -Wall
OBJS=person.o student.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

student.o: ./student.cpp
	$(CC) $(OPTS) -c ./student.cpp

person.o: ./person.cpp
	$(CC) $(OPTS) -c ./person.cpp

clean:
	rm -rf *.o *.dSYM main