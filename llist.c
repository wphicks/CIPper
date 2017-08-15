#include <stdlib.h>
#include <stdio.h>

#include "llist.h"
#include "llnode.h"

llist * build_llist() {
  llist * new_list;
  new_list = malloc(sizeof(llist));
  new_list->head = NULL;
  new_list->size = 0;
  return new_list;
}

void destroy_llist(llist * old_list) {
  llnode * next_node;
  llnode * cur_node = old_list->head;
  while (cur_node) {
    next_node = cur_node->next;
    free(cur_node);
    cur_node = next_node;
  }
  free(old_list);
}

void insert_node(llist * cur_list, llnode * new_node, int index) {
  llnode * cur_node = cur_list->head;
  if (!cur_node){
    cur_list->head = new_node;
    return;
  }
  while (cur_node && index) {
    --index;
    if (!index){
      set_next(new_node, cur_node->next);
      set_next(cur_node, new_node);
      return;
    }
    if (!cur_node->next) {
      set_next(cur_node, new_node);
      return;
    }
    cur_node = cur_node->next;
  }
}

int pop_node(llist * cur_list, int index) {
  int ret_value;
  llnode * prev_node = NULL;
  llnode * cur_node = cur_list->head;
  if (cur_node) {
    ++index;
    do {
      --index;
      if (!index){
        ret_value = cur_node->data;
        if (prev_node) {
          set_next(prev_node, cur_node->next);
        } else {
          cur_list->head = cur_node->next;
        }
        free(cur_node);
        break;
      }
      prev_node = cur_node;
      cur_node = cur_node->next;
    } while (cur_node && index);
  }
  return ret_value;
}


int get_data(llist * cur_list, int index) {
  llnode * cur_node = cur_list->head;
  while (cur_node && index) {
    --index;
    if(!index) {
      return cur_node->data;
    }
    cur_node = cur_node->next;
  }
  return cur_node->data;
}

void insert_item(llist * cur_list, int data, int index) {
  llnode * new_node = build_llnode();
  set_data(new_node, data);
  insert_node(cur_list, new_node, index);
}

void print_list(llist * cur_list) {
  llnode * cur_node = cur_list->head;
  printf("[");
  while (cur_node) {
    printf("%d", cur_node->data);
    if (cur_node->next) {
      printf(", ");
    }
    cur_node = cur_node->next;
  }
  printf("]\n");
}
