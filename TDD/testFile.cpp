#include <stdio.h>
#include <gtest/gtest.h>
#include "Dollar.hpp"

// TEST(test_case_name, test_name) {
//   EXPECT_EQ(1, multi(1,1));
//   //EXPECT_EQ는 result가 1*1는 1이기때문에 1을 넣어줘야함.
// }

//test_case_name, test_name
TEST(test_case_name, testMultiplication) {
  Dollar five = Dollar(5);
	five.times(2);
  EXPECT_EQ(10, five._amount);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}