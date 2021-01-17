SHELL = /bin/bash

SEQUENCEAPP = sequenceapp.o Responder.o Keeper.o Request.o Response.o
TREEOBJS = testTree.o Node.o Tree.o
TESTTREE2 = testTree2.o
TIMERAPP = timerapp.o Timer.o
CFLAGS = -Wall -g
CTYPE = -std=c++11
CC = g++
LIBS = -lm 
THREADS	= -pthread

sequenceapp:${SEQUENCEAPP}
	${CC} ${CFLAGS} -o $@ ${SEQUENCEAPP} ${LIBS} ${THREADS} 

testTree:${TREEOBJS}
	${CC} ${CFLAGS} -o $@ ${TREEOBJS} ${LIBS}

testTree2:${TESTTREE2}
	${CC} ${CFLAGS} -o $@ ${TESTTREE2} ${LIBS}

timerapp:${TIMERAPP}
	${CC} ${CFLAGS} -o $@ ${TIMERAPP} ${LIBS} ${THREADS}

all:testTree testTree2 timerapp sequenceapp

clean:
	-clear
	-rm -f *.o core *.core testTree testTree2 timerapp sequenceapp

.cc.o:
	${CC} ${CFLAGS} -c ${THREADS} ${CTYPE} $<
