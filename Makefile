CC = gcc

build: main.o ai.o chess.o io.o
	$(CC) -std=c99 -o zcuchess main.o ai.o chess.o io.o

main.o: main.c
	$(CC) -std=c99 -c main.c -o main.o
	
ai.o: ai.c
	$(CC) -std=c99 -c ai.c -o ai.o

chess.o: chess.c
	$(CC) -std=c99 -c chess.c -o chess.o

io.o: io.c
	$(CC) -std=c99 -c io.c -o io.o
