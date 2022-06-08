all: main.o linkedlist.o
	gcc main.o linkedlist.o -o main -lm

main.o: main.c linkedlist.h
	gcc -I . -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -I . -c linkedlist.c

clean:
	rm -rf *.o
	rm main

