CC=gcc
CFLAGS=-Wall

FILES= src/simplechain.c
project1: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o bin/ass1
clean:
	rm bin/*
