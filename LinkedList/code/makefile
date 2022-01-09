SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0 -std=c++14
LDFLAGS=-lm
TESTLINKEDLISTSOURCES=testLinkedList.cc Integer.cc 
TESTLINKEDLISTOBJS=testLinkedList.o Integer.o
TESTMERGESOURCES=testMerge.cc
TESTMERGEOBJS=testMerge.o

testMerge:$(TESTMERGEOBJS)
	$(CXX) -o $@ ${TESTMERGEOBJS}

testLinkedList:$(TESTLINKEDLISTOBJS)
	$(CXX) -o $@ ${TESTLINKEDLISTOBJS}

all:	testLinkedList	\
	testMerge

clean:
	clear
	@echo "Cleaning up..."
	rm -f  testLinkedList \
		testMerge \
	       	*.o core *.core *.txt *.text

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
