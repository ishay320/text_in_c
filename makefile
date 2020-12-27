CC = gcc -g -Wall
main = main.o
mc = main.c

all: $(mc)
	$(CC) $^ -o main

.PHONY: all clean

clean:
	-rm main