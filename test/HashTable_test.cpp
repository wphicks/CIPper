#include <gtest/gtest.h>
extern "C" {
  #include "htable.h"
}

class HTableTest : public ::testing::Test {
 protected:
  HashTable * test_table;
  virtual void SetUp() {
    test_table = build_htable();
    insert_htable_pair(test_table, "A", 0);
    insert_htable_pair(test_table, "B", 1);
  }

  virtual void TearDown() {
    destroy_htable(test_table);
  }
};

TEST_F(HTableTest, GetValue) {
  EXPECT_EQ(get_htable_value(test_table, "A"), 0);
}

TEST_F(HTableTest, SetValue) {
  EXPECT_EQ(get_htable_value(test_table, "B"), 1);
  set_htable_value(test_table, "B", 2);
  EXPECT_EQ(get_htable_value(test_table, "B"), 2);
  set_htable_value(test_table, "C", 0);
  EXPECT_EQ(get_htable_value(test_table, "C"), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
