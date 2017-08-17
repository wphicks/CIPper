#include "htable.h"

unsigned long hash(char *str) {
}

int bucket_index(unsigned long hash_value){
  return hash_value % BUCKETSIZE;
}
