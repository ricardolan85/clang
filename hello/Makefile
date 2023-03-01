PROJECT = hello

CC = gcc

SRCS = hello.c
OBJS = hello.o

all: ${PROJECT}

${PROJECT}: ${OBJS}
	${CC} ${OBJS} -o ${PROJECT}.exe

${OBJS}: ${SRCS}
	${CC} -c $<

clean:
	del *.o 
	del *.exe