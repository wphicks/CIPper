#pragma once
#include "LinkedList.h"

#define BUCKETSIZE 251

typedef struct {
  HashList * buckets[BUCKETSIZE];
} HashTable;

typedef struct {
  char * key;
  int value;
} HashPair;

int get_htable_value(HashTable * table, char * key);
void set_htable_value(HashTable * table, char * key, int value);
