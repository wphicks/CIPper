#include <gtest/gtest.h>
extern "C" {
  #include "HashTable.h"
}

class HTableTest : public ::testing::Test {
 protected:
  HashTable * test_table;
  char * key1 = "A";
  char * key2 = "BB";
  char * key3 = "C";
  void * data0 = malloc(sizeof(int));
  void * data1 = malloc(sizeof(int));
  void * data2 = malloc(sizeof(int));
  virtual void SetUp() {
    test_table = build_HashTable();
    *((int *) data0) = 0;
    *((int *) data1) = 1;
    *((int *) data2) = 2;
    set_htable_value(test_table, key1, data0);
    set_htable_value(test_table, key2, data1);
  }

  virtual void TearDown() {
    destroy_HashTable(test_table);
    free(data0);
    free(data1);
    free(data2);
  }
};

TEST_F(HTableTest, GetValue) {
  EXPECT_EQ(*((int *) get_htable_value(test_table, key1)), 0);
}

TEST_F(HTableTest, SetValue) {
  EXPECT_EQ(*((int *) get_htable_value(test_table, key2)), 1);
  set_htable_value(test_table, key2, data2);
  EXPECT_EQ(*((int *) get_htable_value(test_table, key2)), 2);
  set_htable_value(test_table, key3, data0);
  EXPECT_EQ(*((int *) get_htable_value(test_table, key3)), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
