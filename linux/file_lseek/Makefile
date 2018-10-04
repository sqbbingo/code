EXE = file_lseek
OBJ = file_lseek.o
SRC = file_lseek.c
CC = gcc

CFLAGS = -g
LDFLAGS =

EXE:$(OBJ)
	$(CC) $(LDFLAGS) -o $(EXE) $^

OBJ:$(SRC)
	$(CC) $(CFLAGS) -o -c OBJ $^

.PHONY:clean
clean:
	-$(RM) $(OBJ) $(EXE)
