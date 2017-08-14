CC=clang
CFLAGS=-g -Wall -std=c99
PROFFLAGS=-pg -Wall -std=c99
INCFLAGS=-I.

TARGETS=factorial

all : $(TARGETS)

factorial: factorial.o main.c
	$(CC) $(CFLAGS) factorial.o main.c -o factorial

factorial.o: factorial.c factorial.h
	$(CC) $(INCFLAGS) -c factorial.c

% : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(TARGETS)

