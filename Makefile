INCDIR=include
SRCDIR=src
BUILDDIR=build
TESTDIR=test

CC=clang
CFLAGS=-g -Wall -std=c99
PROFFLAGS=-pg -Wall -std=c99
INCFLAGS=-I$(INCDIR)
LDTESTFLAGS=-lgtest -lgtest_main -lpthread

CXX=clang++
CXXFLAGS=-g -Wall -std=c++14

TARGETS=llist

all : $(TARGETS)

test: factorial_test

factorial_test: factorial.o
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(BUILDDIR)/factorial.o $(TESTDIR)/factorial.cpp $(LDTESTFLAGS) -o $(BUILDDIR)/factorial_test
	$(BUILDDIR)/factorial_test

llist: llist.o llnode.o $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(INCFLAGS) $(BUILDDIR)/llnode.o $(BUILDDIR)/llist.o $(SRCDIR)/main.c -o $(BUILDDIR)/llist

llist.o: $(SRCDIR)/llist.c $(INCDIR)/llist.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/llist.c -o $(BUILDDIR)/llist.o

llnode.o: $(SRCDIR)/llnode.c $(INCDIR)/llnode.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/llnode.c -o $(BUILDDIR)/llnode.o

factorial.o: $(SRCDIR)/factorial.c $(INCDIR)/factorial.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/factorial.c -o $(BUILDDIR)/factorial.o

clean:
	rm $(BUILDDIR)/*

