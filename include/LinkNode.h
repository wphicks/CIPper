#pragma once
typedef struct iLinkNode {
  struct iLinkNode * next;
  void * data;
} LinkNode;

LinkNode * build_LinkNode();
void destroy_LinkNode(LinkNode * old_node);
void * get_data(LinkNode * node);
void set_data(LinkNode * node, void * data);
void set_next(LinkNode * node, LinkNode * next);
LinkNode * get_next(LinkNode * node);
