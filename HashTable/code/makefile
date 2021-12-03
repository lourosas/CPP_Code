SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0
LDFLAGS=-lm
PNFINDERSOURCES=testPrimeNumberFinder.cc PrimeNumberFinder.cc
PNFINDEROBJS=testPrimeNumberFinder.o PrimeNumberFinder.o

testPrimeNumberFinder:$(PNFINDEROBJS)
	${CXX} $(CFLAGS) $(LDFLAGS) -c $(PNFINDERSOURCES)
	$(CXX) -o testPrimeNumberFinder $(PNFINDEROBJS)

all:	testPrimeNumberFinder
clean:
	clear
	@echo "Cleaning up..."
	rm -f testPrimeNumberFinder *.o core *.core *.txt

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
