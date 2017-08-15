CC=clang
CFLAGS=-g -Wall -std=c99
PROFFLAGS=-pg -Wall -std=c99
INCFLAGS=-I.

TARGETS=llist

all : $(TARGETS)

llist: llist.o llnode.o main.c
	$(CC) $(CFLAGS) llnode.o llist.o main.c -o llist

llist.o: llist.c llist.h
	$(CC) $(INCFLAGS) -c llist.c

llnode.o: llnode.c llnode.h
	$(CC) $(INCFLAGS) -c llnode.c

% : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(TARGETS) *.o

