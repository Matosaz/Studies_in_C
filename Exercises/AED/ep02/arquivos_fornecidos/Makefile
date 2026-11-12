CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

.PHONY: all debug clean

all: ranking

ranking: main.o aluno.o
	$(CC) $(CFLAGS) -o ranking main.o aluno.o

debug:
	$(CC) $(CFLAGS) -DDEBUG -o ranking_debug main.c aluno.c debug.c

main.o: main.c estrutura.h
	$(CC) $(CFLAGS) -c main.c

aluno.o: aluno.c estrutura.h
	$(CC) $(CFLAGS) -c aluno.c

debug.o: debug.c debug.h estrutura.h
	$(CC) $(CFLAGS) -c debug.c

clean:
	rm -f *.o ranking ranking.exe ranking_debug ranking_debug.exe ranking_debug.txt
