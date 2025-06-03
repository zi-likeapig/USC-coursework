#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CountNumberOfSpaces, Test1) {
  EXPECT_EQ(CountNumberOfSpaces("Hello"), 0);
}

TEST(CountNumberOfSpaces, Test2) {
  EXPECT_EQ(CountNumberOfSpaces("Hello world!"), 1);
}

TEST(CountNumberOfSpaces, Test3) {
  EXPECT_EQ(CountNumberOfSpaces("Hello 1"), 1);
}

TEST(CountNumberOfSpaces, Test4) {
  EXPECT_EQ(CountNumberOfSpaces("Hello /"), 1);
}

TEST(CountNumberOfSpaces, Test5) {
  EXPECT_EQ(CountNumberOfSpaces("Hello  /"), 2);
}

TEST(CountNumberOfSpaces, Test6) {
  EXPECT_EQ(CountNumberOfSpaces(" Hello /"), 2);
}

TEST(CountNumberOfSpaces, Test7) {
  EXPECT_EQ(CountNumberOfSpaces("Hello / "), 2);
}

TEST(CountNumberOfSpaces, Test8) {
  EXPECT_EQ(CountNumberOfSpaces("  Hello  /  "), 6);
}

TEST(CountNumberOfSpaces, Test9) {
  EXPECT_EQ(CountNumberOfSpaces("  Hello  /  1"), 6);
}

TEST(CountNumberOfSpaces, Test10) {
  EXPECT_EQ(CountNumberOfSpaces("  Hello  /  12  "), 8);
}