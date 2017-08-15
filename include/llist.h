#pragma once
#include "llnode.h"
typedef struct {
  llnode * head;
  size_t size;
} llist;

llist * build_llist();
void destroy_llist(llist * old_list);
void insert_node(llist * cur_list, llnode * new_node, int index);
int pop_node(llist * cur_list, int index);
int get_data(llist * cur_list, int index);
void insert_item(llist * cur_list, int data, int index);
void print_list(llist * cur_list);
