# -*-Makefile -*-
CC=g++
OPTS=-g -Wall -std=c++11
OBJS=order_test.o order_cache.o order.o order_cache_test.o

test: ./test.cpp $(OBJS)
	$(CC) $(OPTS) -o test test.cpp $(OBJS)

order_test.o: ./order_test.cpp
	$(CC) $(OPTS) -c ./order_test.cpp

order_cache_test.o: ./order_cache_test.cpp
	$(CC) $(OPTS) -c ./order_cache_test.cpp

order_cache.o: ../order_cache.cpp
	$(CC) $(OPTS) -c ../order_cache.cpp

order.o: ../order.cpp
	$(CC)  $(OPTS) -c ../order.cpp

clean:
	rm -rf *.o *.dSYM test