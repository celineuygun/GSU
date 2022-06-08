all: main.o exam_string.o
	gcc main.o exam_string.o -o main

main.o: main.c exam_string.h
	gcc -I . -c main.c

exam_string.o: exam_string.c exam_string.h
	gcc -I . -c exam_string.c

clean:
	rm -rf *.o
	rm main freqs.txt
