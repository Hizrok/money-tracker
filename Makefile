
PROG=main
CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -pedantic

.PHONY: all run test clean

all: $(PROG)

run: $(PROG)
	./$(PROG)

%.o: %.c *.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o $(PROG)