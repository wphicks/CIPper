#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

typedef struct {
  char * key;
  void * value;
} HashPair;

HashPair * build_HashPair() {
  HashPair * pair = malloc(sizeof(HashPair));
  pair->key = NULL;
  pair->value = NULL;
  return pair;
}

void destroy_HashPair(HashPair * pair) {
  free(pair);
}

HashTable * build_HashTable() {
  int i;
  HashTable * table = malloc(sizeof(HashTable));
  for (i = 0; i < BUCKETSIZE; ++i) {
    (table->buckets)[i] = build_LinkedList();
  }
  return table;
}

void destroy_HashTable(HashTable * table) {
  int i;
  LinkedList * cur_bucket;
  LinkNode * cur_node;
  for (i = 0; i < BUCKETSIZE; ++i) {
    cur_bucket = (table->buckets)[i];
    cur_node = cur_bucket->head;
    while(cur_node) {
      destroy_HashPair((HashPair *) get_data(cur_node));
      cur_node = cur_node->next;
    }
    destroy_LinkedList(cur_bucket);
  }
  free(table);
}

unsigned long hash(char *str) {
  int cur;
  unsigned long hash = 5381;
  while ((cur = (*str++))) {
    hash = hash * 33 ^ cur;
  }
  return hash;
}

int bucket_index(unsigned long hash_value){
  return hash_value % BUCKETSIZE;
}

LinkedList * get_bucket(HashTable * table, char * key){
  unsigned long key_hash = hash(key);
  int index = bucket_index(key_hash);
  return (table->buckets)[index];
}

HashPair * get_htable_pair(HashTable * table, char * key) {
  HashPair * retrieved = NULL;
  LinkedList * cur_bucket = get_bucket(table, key);
  LinkNode * cur_node = cur_bucket->head;
  while (cur_node) {
    retrieved = (HashPair *) get_data(cur_node);
    if (strcmp(key, retrieved->key) == 0) {
      return retrieved;
    }
    cur_node = get_next(cur_node);
  }
  return NULL;
}

void * get_htable_value(HashTable * table, char * key) {
  HashPair * pair = get_htable_pair(table, key);
  if (pair) {
    return pair->value;
  }
  return NULL;
}

void set_htable_value(HashTable * table, char * key, void * value) {
  LinkedList * cur_bucket;
  HashPair * pair = get_htable_pair(table, key);
  if (pair) {
    pair->value = value;
  } else {
    pair = build_HashPair();
    pair->key = key;
    pair->value = value;
    cur_bucket = get_bucket(table, key);
    append_list_item(cur_bucket, pair);
  }
}
