#include <stdio.h>
#include "llist.h"

int main() {
    int i;
    llist * test_list = build_llist();
    for (i = 0; i < 10; ++i) {
      insert_item(test_list, i, 999);
    }
    insert_item(test_list, 9, 5);
    printf("%d\n", pop_node(test_list, 5));
    pop_node(test_list, 9);
    pop_node(test_list, 5);
    pop_node(test_list, 0);
    print_list(test_list);
}

