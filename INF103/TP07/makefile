all: main.o name.o
	gcc main.o name.o -o main

main.o: main.c name.h
	gcc -I . -c main.c

name.o: name.c name.h
	gcc -I . -c name.c

clean:
	rm -rf *.o
	rm main

