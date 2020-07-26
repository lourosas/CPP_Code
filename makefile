SHELL = /bin/bash

TREEOBJS = testTree.o Node.o Tree.o
TESTTREE2 = testTree2.o
CFLAGS = -Wall -g
CC = g++
LIBS = -lm 

testTree:${TREEOBJS}
	${CC} ${CFLAGS} -o $@ ${TREEOBJS} ${LIBS}

testTree2:${TESTTREE2}
	${CC} ${CFLAGS} -o $@ ${TESTTREE2} ${LIBS}

all:testTree testTree2

clean:
	-clear
	-rm -f *.o core *.core testTree testTree2

.cc.o:
	${CC} ${CFLAGS} -c $<
