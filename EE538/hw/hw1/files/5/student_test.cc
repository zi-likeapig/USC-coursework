#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(ClimbStairs, Zero) {
  EXPECT_EQ(ClimbStairs(0), 0);
}

TEST(ClimbStairs, One) {
  EXPECT_EQ(ClimbStairs(1), 1);
}

TEST(ClimbStairs, Minus) {
  EXPECT_EQ(ClimbStairs(-11), -1);
}

TEST(ClimbStairs, Two) {
  EXPECT_EQ(ClimbStairs(2), 2);
}

TEST(ClimbStairs, Three) {
  EXPECT_EQ(ClimbStairs(3), 4);
}

TEST(ClimbStairs, Eight) {
  EXPECT_EQ(ClimbStairs(8), 81);
}