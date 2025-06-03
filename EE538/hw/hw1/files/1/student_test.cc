#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Reverse, Empty) {
  std::vector<int> in = {}; 
  auto out = Reverse(in);
  std::vector<int> expected = {};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, One) {
  std::vector<int> in = {1};
  auto out = Reverse(in);
  std::vector<int> expected = {1};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, Zero) {
  std::vector<int> in = {0};
  auto out = Reverse(in);
  std::vector<int> expected = {0};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, MinusOne) {
  std::vector<int> in = {-1};
  auto out = Reverse(in);
  std::vector<int> expected = {-1};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, VectorTest1) {
  std::vector<int> in = {1,2,90,0,-13,3};
  auto out = Reverse(in);
  std::vector<int> expected = {3,-13,0,90,2,1};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, VectorTest2) {
  std::vector<int> in = {-12,-12,-12,-12};
  auto out = Reverse(in);
  std::vector<int> expected = {-12,-12,-12,-12};
  EXPECT_EQ(out, expected);
}

TEST(Reverse, VectorTest3) {
  std::vector<int> in = {-12,-5,0,5,12};
  auto out = Reverse(in);
  std::vector<int> expected = {12,5,0,-5,-12};
  EXPECT_EQ(out, expected);
}

//-----------------------------------------------------------------------------
TEST(PlusOne, Empty) {
  std::vector<int> in = {};
  auto out = PlusOne(in);
  std::vector<int> expected = {};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, Zero) {
  std::vector<int> in = {0};
  auto out = PlusOne(in);
  std::vector<int> expected = {1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, One) {
  std::vector<int> in = {1};
  auto out = PlusOne(in);
  std::vector<int> expected = {2};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, N9) {
  std::vector<int> in = {9};
  auto out = PlusOne(in);
  std::vector<int> expected = {1, 0};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, N10) {
  std::vector<int> in = {1,0};
  auto out = PlusOne(in);
  std::vector<int> expected = {1,1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, N1010) {
  std::vector<int> in = {1,0,1,0};
  auto out = PlusOne(in);
  std::vector<int> expected = {1,0,1,1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, N1009) {
  std::vector<int> in = {1,0,0,9};
  auto out = PlusOne(in);
  std::vector<int> expected = {1,0,1,0};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, Err1) {
  std::vector<int> in = {12};
  auto out = PlusOne(in);
  std::vector<int> expected = {-1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, Err2) {
  std::vector<int> in = {-1};
  auto out = PlusOne(in);
  std::vector<int> expected = {-1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, Err3) {
  std::vector<int> in = {1,0,10,0};
  auto out = PlusOne(in);
  std::vector<int> expected = {-1};
  EXPECT_EQ(out, expected);
}

TEST(PlusOne, Err4) {
  std::vector<int> in = {1,0,0,-12};
  auto out = PlusOne(in);
  std::vector<int> expected = {-1};
  EXPECT_EQ(out, expected);
}