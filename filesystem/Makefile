PROJECT = filesystem

CC = gcc

SRCS = dir.c file.c
OBJS = dir.o file.o

all: ${PROJECT}

${PROJECT}: ${OBJS}
	${CC} ${OBJS} -o ${PROJECT}.exe

${OBJS}: ${SRCS}
	${CC} -c $<

clean:
	del *.o 
	del *.exe