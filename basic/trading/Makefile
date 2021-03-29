# -*-Makefile -*-
CC=g++
OPTS=-g -Wall -std=c++11
OBJS=order_cache.o order.o

main: ./main.cpp $(OBJS)
	$(CC) $(OPTS) -o main main.cpp $(OBJS)

order_cache.o: ./order_cache.cpp
	$(CC) $(OPTS) -c ./order_cache.cpp

order.o: ./order.cpp
	$(CC)  $(OPTS) -c ./order.cpp

clean:
	rm -rf *.o *.dSYM main