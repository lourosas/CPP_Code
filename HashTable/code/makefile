SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0 -std=c++14
LDFLAGS=-lm
PNFINDERSOURCES=testPrimeNumberFinder.cc PrimeNumberFinder.cc
PNFINDEROBJS=testPrimeNumberFinder.o PrimeNumberFinder.o
TESTCHAINEDHASHTABLESOURCES=testChainedHashTable.cc Integer.cc	\
			    PrimeNumberFinder.cc
TESTCHAINEDHASHTABLEOBJS=testChainedHashTable.o Integer.o \
			 PrimeNumberFinder.o
TESTINTEGERSOURCES=testInteger.cc Integer.cc
TESTINTEGEROBJS=testInteger.o Integer.o
#TESTLISTHASHSOURCES=testListHashTable.cc Integer.cc \
		PrimeNumberFinder.cc
#TESTLISTHASHOBJS=testListHashTable.o Integer.o \
		PrimeNumberFinder.o
TESTOPENHASHSOURCES=testOpenAddressingHashTable.cc Integer.cc \
		    PrimeNumberFinder.cc
TESTOPENHASHOBJS=testOpenAddressingHashTable.o Integer.o \
		 PrimeNumberFinder.o

testChainedHashTable:${TESTCHAINEDHASHTABLEOBJS}
	${CXX} -o testChainedHashTable ${TESTCHAINEDHASHTABLEOBJS}

testInteger:${TESTINTEGEROBJS}
	${CXX} -o testInteger ${TESTINTEGEROBJS}

#testListHashTable:${TESTLISTHASHOBJS}
#	${CXX} -o testListHashTable ${TESTLISTHASHOBJS}

testOpenAddressingHashTable:$(TESTOPENHASHOBJS)
	$(CXX) -o $@ ${TESTOPENHASHOBJS}

testPrimeNumberFinder:$(PNFINDEROBJS)
	${CXX} $(CFLAGS) $(LDFLAGS) -c $(PNFINDERSOURCES)
	$(CXX) -o testPrimeNumberFinder $(PNFINDEROBJS)

all:	testPrimeNumberFinder \
	testInteger \
	testOpenAddressingHashTable \
	testChainedHashTable \
#	testListHashTable

clean:
	clear
	@echo "Cleaning up..."
	rm -f testPrimeNumberFinder \
		testInteger \
		testOpenAddressingHashTable \
		testChainedHashTable	\
	       	*.o core *.core *.txt *.text

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
