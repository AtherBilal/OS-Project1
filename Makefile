CC=gcc
CFLAGS=-Wall
BASEFILE= src/simplechain.c
Q4=src/simplechain-q4.c
Q5=src/simplechain-q5.c
Q6=src/simplechain-q6.c

HELPERFILES= src/validation.c
base: $(BASEFILE) $(HELPERFILES)
	$(CC) $(CFLAGS) $(BASEFILE) $(HELPERFILES) -o bin/ass1
	$(CC) $(CFLAGS) $(Q4) $(HELPERFILES) -o bin/ass1-q4
	$(CC) $(CFLAGS) $(Q5) $(HELPERFILES) -o bin/ass1-q5
	$(CC) $(CFLAGS) $(Q6) $(HELPERFILES) -o bin/ass1-q6

clean:
	rm bin/*
