all: main.o sorting.o applications.o
	gcc main.o sorting.o applications.c -o main

main.o: main.c sorting.h
	gcc -I . -c main.c

sorting.o: sorting.c sorting.h
	gcc -I . -c sorting.c

applications.o: applications.c applications.h
	gcc -I . -c applications.c

clean:
	rm -rf *.o
	rm main
