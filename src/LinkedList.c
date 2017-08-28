#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "LinkNode.h"

LinkedList * build_LinkedList() {
  LinkedList * new_list;
  new_list = malloc(sizeof(LinkedList));
  new_list->head = NULL;
  new_list->size = 0;
  return new_list;
}

void destroy_LinkedList(LinkedList * old_list) {
  LinkNode * next_node;
  LinkNode * cur_node = old_list->head;
  while (cur_node) {
    next_node = cur_node->next;
    destroy_LinkNode(cur_node);
    cur_node = next_node;
  }
  free(old_list);
}

void insert_node(LinkedList * cur_list, LinkNode * new_node, int index) {
  LinkNode * cur_node = cur_list->head;
  if (!cur_node){
    cur_list->head = new_node;
    return;
  }
  if (!index) {
    cur_list->head = new_node;
    set_next(new_node, cur_node);
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

void append_node(LinkedList * cur_list, LinkNode * new_node) {
  LinkNode * cur_node = cur_list-> head;
  if (!cur_node) {
    cur_list->head = new_node;
  } else {
    while (cur_node->next) {
      cur_node = get_next(cur_node);
    }
    set_next(cur_node, new_node);
  }
}

void * pop_list_node(LinkedList * cur_list, int index) {
  void * ret_value = NULL;
  LinkNode * prev_node = NULL;
  LinkNode * cur_node = cur_list->head;
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


void * get_list_item(LinkedList * cur_list, int index) {
  LinkNode * cur_node = cur_list->head;
  while (cur_node && index) {
    --index;
    cur_node = cur_node->next;
    if(!index) {
      return cur_node->data;
    }
  }
  return cur_node->data;
}

void insert_list_item(LinkedList * cur_list, void * data, int index) {
  LinkNode * new_node = build_LinkNode();
  set_data(new_node, data);
  insert_node(cur_list, new_node, index);
}

void append_list_item(LinkedList * cur_list, void * data){
  LinkNode * new_node = build_LinkNode();
  set_data(new_node, data);
  append_node(cur_list, new_node);
}

void print_int_list(LinkedList * cur_list) {
  LinkNode * cur_node = cur_list->head;
  printf("[");
  while (cur_node) {
    printf("%d", *((int *) cur_node->data));
    if (cur_node->next) {
      printf(", ");
    }
    cur_node = cur_node->next;
  }
  printf("]\n");
}

LinkNode * reverse_nodes(LinkNode * cur_node, LinkNode * next_node) {
  LinkNode * end_node;
  if (next_node->next) {
    end_node = reverse_nodes(next_node, next_node->next);
    next_node->next = cur_node;
    return end_node;
  } else {
    next_node->next = cur_node;
    return next_node;
  }
}

void reverse_list(LinkedList * cur_list){
  LinkNode * old_head = cur_list->head;
  LinkNode * next_node = old_head->next;
  if (next_node) {
    cur_list->head = reverse_nodes(old_head, next_node);
  }
  old_head->next = NULL;
}
