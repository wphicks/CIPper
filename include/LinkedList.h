#pragma once
#include "LinkNode.h"
typedef struct {
  LinkNode * head;
  size_t size;
} LinkedList;

LinkedList * build_LinkedList();
void destroy_LinkedList(LinkedList * old_list);
void * pop_list_node(LinkedList * cur_list, int index);
void * get_list_item(LinkedList * cur_list, int index);
void insert_list_item(LinkedList * cur_list, void * data, int index);
void append_list_item(LinkedList * cur_list, void * data);
void print_int_list(LinkedList * cur_list);
void reverse_list(LinkedList * cur_list);
