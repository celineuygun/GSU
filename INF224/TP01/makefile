CC=gcc
CFLAGS=-g -O2 -Wall
LDFLAGS=-lm

DEPS = lib.h
OBJS = lib.o main.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o main
