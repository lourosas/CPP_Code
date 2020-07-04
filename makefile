SHELL = /bin/bash

TREEOBJS = testTree.o Node.o Tree.o
CFLAGS = -Wall -g
CC = g++
LIBS = -lm 

testTree:${TREEOBJS}
	${CC} ${CFLAGS} -o $@ ${TREEOBJS} ${LIBS}

clean:
	-clear
	-rm -f *.o core *.core testTree

.cc.o:
	${CC} ${CFLAGS} -c $<
