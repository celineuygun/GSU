all: main.o contactlist.o
	gcc main.o contactlist.o -o main -lm

main.o: main.c contactlist.h
	gcc -I . -c main.c

contactlist.o: contactlist.c contactlist.h
	gcc -I . -c contactlist.c

clean:
	rm -rf *.o
	rm main

