CC=gcc
CFLAGS=-Wall
FILES= src/simplechain.c
HELPERFILES= src/validation.c
project1: $(FILES) $(HELPERFILES)
	$(CC) $(CFLAGS) $(FILES) $(HELPERFILES) -o bin/ass1
clean:
	rm bin/*
