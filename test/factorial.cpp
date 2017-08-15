#include <gtest/gtest.h>
extern "C" {
#include "factorial.h"
}

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(1, factorial(0));
}

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(720, factorial(6));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
