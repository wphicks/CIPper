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

TARGETS=test
TESTS=$(BUILDDIR)/factorial_test $(BUILDDIR)/LinkNode_test $(BUILDDIR)/LinkedList_test $(BUILDDIR)/HashTable_test

all : $(TARGETS)

all_test: test memtest

test: $(TESTS)
	for test_file in $(TESTS) ; do\
	    $$test_file  || exit 1; \
	done

memtest: $(TESTS)
	for test_file in $(TESTS) ; do\
	    valgrind --tool=memcheck $$test_file  || exit 1; \
	done

# Factorial used as sanity check
$(BUILDDIR)/factorial.o: $(SRCDIR)/factorial.c $(INCDIR)/factorial.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/factorial.c -o $(BUILDDIR)/factorial.o

$(BUILDDIR)/factorial_test: $(BUILDDIR)/factorial.o
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(BUILDDIR)/factorial.o $(TESTDIR)/factorial.cpp $(LDTESTFLAGS) -o $(BUILDDIR)/factorial_test

$(BUILDDIR)/LinkNode.o: $(SRCDIR)/LinkNode.c $(INCDIR)/LinkNode.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/LinkNode.c -o $(BUILDDIR)/LinkNode.o

$(BUILDDIR)/LinkNode_test: $(BUILDDIR)/LinkNode.o $(TESTDIR)/LinkNode_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(BUILDDIR)/LinkNode.o $(TESTDIR)/LinkNode_test.cpp $(LDTESTFLAGS) -o $(BUILDDIR)/LinkNode_test

$(BUILDDIR)/LinkedList.o: $(SRCDIR)/LinkedList.c $(INCDIR)/LinkedList.h $(BUILDDIR)/LinkNode.o 
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/LinkedList.c -o $(BUILDDIR)/LinkedList.o

$(BUILDDIR)/LinkedList_test: $(BUILDDIR)/LinkedList.o $(TESTDIR)/LinkedList_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(BUILDDIR)/LinkedList.o $(BUILDDIR)/LinkNode.o $(TESTDIR)/LinkedList_test.cpp $(LDTESTFLAGS) -o $(BUILDDIR)/LinkedList_test

$(BUILDDIR)/HashTable.o: $(SRCDIR)/HashTable.c $(INCDIR)/HashTable.h $(BUILDDIR)/LinkedList.o 
	$(CC) $(CFLAGS) $(INCFLAGS) -c $(SRCDIR)/HashTable.c -o $(BUILDDIR)/HashTable.o

$(BUILDDIR)/HashTable_test: $(BUILDDIR)/HashTable.o $(TESTDIR)/HashTable_test.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(BUILDDIR)/HashTable.o $(BUILDDIR)/LinkedList.o $(BUILDDIR)/LinkNode.o $(TESTDIR)/HashTable_test.cpp $(LDTESTFLAGS) -o $(BUILDDIR)/HashTable_test

clean:
	rm $(BUILDDIR)/*

