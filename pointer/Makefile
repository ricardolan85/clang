PROJECT = pointer

CC = gcc

SRCS = pointer.c
OBJS = pointer.o

all: ${PROJECT}

${PROJECT}: ${OBJS}
	${CC} ${OBJS} -o ${PROJECT}.exe

${OBJS}: ${SRCS}
	${CC} -c $<

clean:
	del *.o 
	del *.exe