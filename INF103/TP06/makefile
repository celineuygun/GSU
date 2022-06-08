all: main.o patient.o
	gcc main.o patient.o -o main

main.o: main.c patient.h
	gcc -I . -c main.c

patient.o: patient.c patient.h
	gcc -I . -c patient.c

clean:
	rm -rf *.o
	rm main