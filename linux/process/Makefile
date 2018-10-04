EXE1 = write
EXE2 = read

OBJ1 = write.o
OBJ2 = read.o

SRC1 = write.c
SRC2 = read.c

CC = gcc	#编译器

#编译参数
CFLAGS = -g
LDFLAGS =

EXE1:$(OBJ1)	#通过依赖项生成目标文件
	$(CC) $(LEFLAGS) -o $(EXE1) $^
OBJ1:$(SRC1) 	#生成.o文件
	$(CC) $(CFLAGS) -o $(OBJ1) -c $^
EXE1:$(OBJ2)	#通过依赖项生成目标文件
	$(CC) $(LEFLAGS) -o $(EXE2) $^
OBJ1:$(SRC2) 	#生成.o文件
	$(CC) $(CFLAGS) -o $(OBJ2) -c $^

.PHONY:clean
clean:
	-$(RM) $(OBJ1) $(EXE1) $(OBJ2) $(EXE2) 
