#pragma once
#include "LinkedList.h"

#define BUCKETSIZE 251

typedef struct {
  LinkedList * buckets[BUCKETSIZE];
} HashTable;

HashTable * build_HashTable();
void destroy_HashTable(HashTable * table);
void * get_htable_value(HashTable * table, char * key);
void set_htable_value(HashTable * table, char * key, void * value);
