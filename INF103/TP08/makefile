all: main.o calculator.o
	gcc main.o calculator.o -o main

main.o: main.c calculator.h
	gcc -I . -c main.c

calculator.o: calculator.c calculator.h
	gcc -I . -c calculator.c

clean:
	rm -rf *.o
	rm main

