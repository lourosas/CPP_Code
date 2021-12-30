SHELL = /bin/bash
CC=gcc
CXX=g++ 
CFLAGS=-g -Wall -O0 -std=c++11
LDFLAGS=-lm
TESTLINKEDLISTSOURCES=testLinkedList.cc Integer.cc 
TESTLINKEDLISTOBJS=testLinkedList.o Integer.o

testLinkedList:$(TESTLINKEDLISTOBJS)
	$(CXX) -o $@ ${TESTLINKEDLISTOBJS}

all:	testLinkedList

clean:
	clear
	@echo "Cleaning up..."
	rm -f  testLinkedList \
	       	*.o core *.core *.txt *.text

.cc.o:
	${CXX} ${CFLAGS} ${LDFLAGS} -c $<
