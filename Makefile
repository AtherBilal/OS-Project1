CC=gcc
CFLAGS=-Wall
BASEFILE= src/simplechain.c
Q4=src/simplechain-q4.c
HELPERFILES= src/validation.c
base: $(BASEFILE) $(HELPERFILES)
	$(CC) $(CFLAGS) $(BASEFILE) $(HELPERFILES) -o bin/ass1
	$(CC) $(CFLAGS) $(BASEFILE) $(HELPERFILES) -o bin/ass1-q4	
clean:
	rm bin/*
