all: main.o strassen.o
	gcc main.o strassen.o -o main

main.o: main.c strassen.h
	gcc -I . -c main.c

calculator.o: strassen.c strassen.h
	gcc -I . -c strassen.c

clean:
	rm -rf *.o
	rm main

