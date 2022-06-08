CC=gcc -O3 -march=native -mtune=native -std=c99

DEPS = hw.h
OBJS = merge_sort.o quick_sort.o shell_sort.o bubble_sort.o selection_sort.o insertion_sort.o utils.o hw.o

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

hw: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm *.o hw performans.pdf perf.txt
