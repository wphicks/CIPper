#include <stdlib.h>
#include <LinkNode.h>
LinkNode * build_LinkNode() {
  LinkNode * new_node = malloc(sizeof(LinkNode));
  set_next(new_node, NULL);
  set_data(new_node, NULL);
  return new_node;
}

void destroy_LinkNode(LinkNode * old_node) {
  /*LinkNode does not own its data; user is responsible for freeing stored
   * items*/
  free(old_node);
}

void * get_data(LinkNode * node) {
  return node->data;
}

void set_data(LinkNode * node, void * data) {
  node->data = data;
}

void set_next(LinkNode * node, LinkNode * next) {
  node->next = next;
}

LinkNode * get_next(LinkNode * node) {
  return node->next;
}
