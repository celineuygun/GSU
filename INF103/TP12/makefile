CC=gcc -O3 -march=native -mtune=native -std=c99

DEPS = main.h
OBJS = heap.o quick_sort.o main.o

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm *.o main