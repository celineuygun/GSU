CC=gcc
CFLAGS=-g -O2 -Wall
LDFLAGS=

DEPS = tree.h queue.h treeAVL.h
OBJS = tree.o queue.o treeAVL.o main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o main
