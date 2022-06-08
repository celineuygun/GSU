all: main.o module.o
	gcc main.o structpoint.o -o main -lm

main.o: main.c structpoint.h
	gcc -I . -c main.c

module.o: structpoint.c structpoint.h
	gcc -I . -c structpoint.c

clean:
	rm -rf *.o
	rm main