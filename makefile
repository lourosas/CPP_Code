SHELL = /bin/bash

TREEOBJS = testTree.o Node.o Tree.o
TESTTREE2 = testTree2.o
TIMERAPP = timerapp.o Timer.o
CFLAGS = -Wall -g
CC = g++
LIBS = -lm 
THREADS	= -pthread

testTree:${TREEOBJS}
	${CC} ${CFLAGS} -o $@ ${TREEOBJS} ${LIBS}

testTree2:${TESTTREE2}
	${CC} ${CFLAGS} -o $@ ${TESTTREE2} ${LIBS}

timerapp:${TIMERAPP}
	${CC} ${CFLAGS} ${THREADS} -o $@ ${TIMERAPP} ${LIBS} ${THREADS}

all:testTree testTree2 timerapp

clean:
	-clear
	-rm -f *.o core *.core testTree testTree2 timerapp

.cc.o:
	${CC} ${CFLAGS} -c $<
