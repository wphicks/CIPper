#include <stdlib.h>
#include <llnode.h>
llnode * build_llnode() {
  llnode * new_node = malloc(sizeof(llnode));
  set_next(new_node, NULL);
  set_data(new_node, 0);
  return new_node;
}

void destroy_llnode(llnode * old_node) {
  free(old_node);
}

void set_data(llnode * node, int data) {
  node->data = data;
}

void set_next(llnode * node, llnode * next) {
  node->next = next;
}
