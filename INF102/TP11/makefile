all: main.o Movies.o
	gcc main.o Movies.o -o main -lm

main.o: main.c Movies.h
	gcc -I . -c  main.c 

Movies.o: Movies.c Movies.h
	gcc -I . -c Movies.c

clean:
	rm -rf *.o
	rm main
