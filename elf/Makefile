PROJECT = elf

CC = gcc

SRCS = elf.c
OBJS = elf.o

all: ${PROJECT}

${PROJECT}: ${OBJS}
	${CC} ${OBJS} -o ${PROJECT}

${OBJS}: ${SRCS}
	${CC} -c $<

clean:
	del *.o 
	del ${PROJECT}