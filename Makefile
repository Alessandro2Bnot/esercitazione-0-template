CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Werror

.PHONY: all clean

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

eco: eco.c
	$(CC) $(CFLAGS) -o $@ $<

eco2: eco2.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f hello eco
