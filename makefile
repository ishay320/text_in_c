CC = gcc -g -Wall
mo = isort txtfind
mc = main.c

all: $(mo)
isort: isort.c
	$(CC) $^ -o $@
txtfind: txtfind.c
	$(CC) $^ -o $@

.PHONY: all clean
clean:
	-rm isort txtfind