build: main.o ai.o chess.o io.o
	gcc -std=c99 -o zcuchess main.o ai.o chess.o io.o

main.o: main.c
	gcc -std=c99 -c main.c -o main.o
	
ai.o: ai.c
	gcc -std=c99 -c ai.c -o ai.o

chess.o: chess.c
	gcc -std=c99 -c chess.c -o chess.o

io.o: io.c
	gcc -std=c99 -c io.c -o io.o