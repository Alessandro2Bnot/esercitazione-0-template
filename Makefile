CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Werror
TARGET = hello

.PHONY: all clean

all: $(TARGET)

$(TARGET): hello.c
	$(CC) $(CFLAGS) -o $(TARGET) hello.c

clean:
	rm -f $(TARGET)