SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0 -std=c++11
LDFLAGS=-lm
PNFINDERSOURCES=testPrimeNumberFinder.cc PrimeNumberFinder.cc
PNFINDEROBJS=testPrimeNumberFinder.o PrimeNumberFinder.o
TESTINTEGERSOURCES=testInteger.cc Integer.cc
TESTINTEGEROBJS=testInteger.o Integer.o
TESTOPENHASHSOURCES=testOpenAddressingHashTable.cc Integer.cc \
		    PrimeNumberFinder.cc
TESTOPENHASHOBJS=testOpenAddressingHashTable.o Integer.o \
		 PrimeNumberFinder.o

testInteger:${TESTINTEGEROBJS}
	${CXX} -o testInteger ${TESTINTEGEROBJS}

testOpenAddressingHashTable:$(TESTOPENHASHOBJS)
	$(CXX) -o $@ ${TESTOPENHASHOBJS}

testPrimeNumberFinder:$(PNFINDEROBJS)
	${CXX} $(CFLAGS) $(LDFLAGS) -c $(PNFINDERSOURCES)
	$(CXX) -o testPrimeNumberFinder $(PNFINDEROBJS)

all:	testPrimeNumberFinder \
	testInteger \
	testOpenAddressingHashTable
clean:
	clear
	@echo "Cleaning up..."
	rm -f testPrimeNumberFinder \
		testInteger \
		testOpenAddressingHashTable \
	       	*.o core *.core *.txt

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
