SHELL = /bin/sh

OBJS =  main.o Mystring.o
CFLAG = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm
TARGET = executable

${TARGET}:${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
