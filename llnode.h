#pragma once
typedef struct illnode{
  struct illnode * next;
  int data;
} llnode;

llnode * build_llnode();
void set_data(llnode * node, int data);
void set_next(llnode * node, llnode * next);
