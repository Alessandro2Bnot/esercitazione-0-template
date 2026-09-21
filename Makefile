CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Werror

.PHONY: all check check-hello check-eco check-all clean

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

eco: eco.c
	$(CC) $(CFLAGS) -o $@ $<

check: check-hello

check-hello: hello
	python3 verifica.py hello

check-eco: eco
	python3 verifica.py eco

check-all: check-hello check-eco

clean:
	rm -f hello eco
