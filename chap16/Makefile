SHELL = /bin/sh

OBJS =  main.o Account.o I_Printable.o Account_Util.o Checking_Account.o Savings_Account.o Trust_Account.o
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
