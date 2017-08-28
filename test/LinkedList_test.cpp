#include <gtest/gtest.h>
extern "C" {
  #include "LinkedList.h"
}

class LinkedListTest : public ::testing::Test {
 protected:
  LinkedList * test_list;
  int test_data[5] = {0, 1, 2, 3, 4};
  virtual void SetUp() {
    test_list = build_LinkedList();
  }

  virtual void TearDown() {
    destroy_LinkedList(test_list);
  }
};

TEST_F(LinkedListTest, DataTest) {
  EXPECT_EQ(nullptr, test_list->head);
  for (int i = 0; i < 5; ++i) {
    insert_list_item(test_list, (void *) (test_data + i), 6);
  }
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(test_data[i], *((int *) get_list_item(test_list, i)));
  }
}

TEST_F(LinkedListTest, AppendTest) {
  EXPECT_EQ(nullptr, test_list->head);
  for (int i = 0; i < 5; ++i) {
    append_list_item(test_list, (void *) (test_data + i));
  }
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(test_data[i], *((int *) get_list_item(test_list, i)));
  }
}

TEST_F(LinkedListTest, InsertPopTest) {
  insert_list_item(test_list, (void *) (test_data + 1), 0); /*{1}*/
  insert_list_item(test_list, (void *) (test_data + 3), 1); /*{1, 3}*/
  insert_list_item(test_list, (void *) (test_data + 2), 1); /*{1, 2, 3}*/
  insert_list_item(test_list, (void *) (test_data + 0), 0); /*{0, 1, 2, 3}*/
  insert_list_item(test_list, (void *) (test_data + 4), 4); /*{0, 1, 2, 3, 4}*/
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(test_data[i], *((int *) get_list_item(test_list, i)));
  }
}

TEST_F(LinkedListTest, ReverseTest) {
  for (int i = 0; i < 5; ++i) {
    append_list_item(test_list, (void *) (test_data + i));
  }
  reverse_list(test_list);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(test_data[4 - i], *((int *) get_list_item(test_list, i)));
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
