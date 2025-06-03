#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CalculatorTest, Zero1) {
  float a = 0;
  float b = -3;
  float sum, diff, product, ratio;
  ErrorCode error_code = Calculator(a, b, sum, diff, product, ratio);
  EXPECT_EQ(error_code, ErrorCode::kNoError);
  EXPECT_FLOAT_EQ(sum, -3);
  EXPECT_FLOAT_EQ(diff, 3);
  EXPECT_FLOAT_EQ(product, 0);
  EXPECT_FLOAT_EQ(ratio, 0);
}

TEST(CalculatorTest, Zero2) {
  float a = 2;
  float b = 0;
  float sum, diff, product, ratio;
  ErrorCode error_code = Calculator(a, b, sum, diff, product, ratio);
  EXPECT_EQ(error_code, ErrorCode::kDivideByZero);
  EXPECT_FLOAT_EQ(sum, 2);
  EXPECT_FLOAT_EQ(diff, 2);
  EXPECT_FLOAT_EQ(product, 0);
}

TEST(CalculatorTest, Test1) {
  float a = -5;
  float b = -2.5;
  float sum, diff, product, ratio;
  ErrorCode error_code = Calculator(a, b, sum, diff, product, ratio);
  EXPECT_EQ(error_code, ErrorCode::kNoError);
  EXPECT_FLOAT_EQ(sum, -7.5);
  EXPECT_FLOAT_EQ(diff, -2.5);
  EXPECT_FLOAT_EQ(product, 12.5);
  EXPECT_FLOAT_EQ(ratio, 2);
}

TEST(CalculatorTest, Test2) {
  float a = -5;
  float b = 15;
  float sum, diff, product, ratio;
  ErrorCode error_code = Calculator(a, b, sum, diff, product, ratio);
  EXPECT_EQ(error_code, ErrorCode::kNoError);
  EXPECT_FLOAT_EQ(sum, 10);
  EXPECT_FLOAT_EQ(diff, -20);
  EXPECT_FLOAT_EQ(product, -75);
  EXPECT_FLOAT_EQ(ratio, -1/3.0);
}

TEST(CalculatorTest, Test3) {
  float a = 1700;
  float b = -13;
  float sum, diff, product, ratio;
  ErrorCode error_code = Calculator(a, b, sum, diff, product, ratio);
  EXPECT_EQ(error_code, ErrorCode::kNoError);
  EXPECT_FLOAT_EQ(sum, 1687);
  EXPECT_FLOAT_EQ(diff, 1713);
  EXPECT_FLOAT_EQ(product, -22100);
  EXPECT_FLOAT_EQ(ratio, -1700/13.0);
}