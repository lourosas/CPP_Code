SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0
LDFLAGS=-lm
PNFINDERSOURCES=testPrimeNumberFinder.cc PrimeNumberFinder.cc
PNFINDEROBJS=testPrimeNumberFinder.o PrimeNumberFinder.o
TESTINTEGERSOURCES=testInteger.cc Integer.cc
TESTINTEGEROBJS=testInteger.o Integer.o

testInteger:${TESTINTEGEROBJS}
	${CXX} -o testInteger ${TESTINTEGEROBJS}
testPrimeNumberFinder:$(PNFINDEROBJS)
	${CXX} $(CFLAGS) $(LDFLAGS) -c $(PNFINDERSOURCES)
	$(CXX) -o testPrimeNumberFinder $(PNFINDEROBJS)

all:	testPrimeNumberFinder testInteger
clean:
	clear
	@echo "Cleaning up..."
	rm -f testPrimeNumberFinder \
		testInteger \
	       	*.o core *.core *.txt

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
