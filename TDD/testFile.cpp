#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"

//test_case_name, test_name
TEST(test_case_name, testMultiplication) {
  Dollar five = Dollar(5);
  Dollar product = five.times(2);
  EXPECT_EQ(10, product._amount);
  product = five.times(3);
  EXPECT_EQ(15, product._amount);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}