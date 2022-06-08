all: main.o hash.o
	gcc main.o hash.o -o main

main.o: main.c hash.h
	gcc -I . -c main.c

hash.o: hash.c hash.h
	gcc -I . -c hash.c

clean:
	rm -rf *.o
	rm main

