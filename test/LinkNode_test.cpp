#include <stdlib.h>
#include <gtest/gtest.h>
extern "C" {
  #include "LinkNode.h"
}

class LinkNodeTest : public ::testing::Test {
 protected:
  LinkNode * test_node;
  LinkNode * next_node;
  void * test_data;
  virtual void SetUp() {
    test_node = build_LinkNode();
    next_node = build_LinkNode();
    test_data = malloc(sizeof(int));
    *((int *) test_data) = 9;
  }

  virtual void TearDown() {
    destroy_LinkNode(test_node);
    destroy_LinkNode(next_node);
    free(test_data);
  }
};

TEST_F(LinkNodeTest, DataTest) {
  EXPECT_EQ(nullptr, get_data(test_node));
  set_data(test_node, test_data);
  EXPECT_EQ(*((int *) get_data(test_node)), *((int *) test_data));
}

TEST_F(LinkNodeTest, NextTest) {
  EXPECT_EQ(nullptr, get_next(test_node));
  set_next(test_node, next_node);
  EXPECT_EQ(next_node, get_next(test_node));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
