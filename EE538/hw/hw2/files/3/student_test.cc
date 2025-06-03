#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(SwapByPointer, test1) {
    float a = 3.5, b = 7.2;
    SwapByPointer(&a, &b);
    EXPECT_FLOAT_EQ(a, 7.2);
    EXPECT_FLOAT_EQ(b, 3.5);
}
TEST(SwapByPointer, test2) {
    float a = 0, b = -7.2;
    SwapByPointer(&a, &b);
    EXPECT_FLOAT_EQ(a, -7.2);
    EXPECT_FLOAT_EQ(b, 0);
}
TEST(SwapByPointer, test3) {
    float a = 1, b = 2;
    SwapByPointer(&a, &b);
    EXPECT_FLOAT_EQ(a, 2);
    EXPECT_FLOAT_EQ(b, 1);
}

TEST(SwapByReference, test1) {
    float a = -2.1, b = 5.8;
    SwapByReference(a, b);
    EXPECT_FLOAT_EQ(a, 5.8);
    EXPECT_FLOAT_EQ(b, -2.1);
}
TEST(SwapByReference, test2) {
    float a = -1, b = 0;
    SwapByReference(a, b);
    EXPECT_FLOAT_EQ(a, 0);
    EXPECT_FLOAT_EQ(b, -1);
}
TEST(SwapByReference, test3) {
    float a = 1, b = 2;
    SwapByReference(a, b);
    EXPECT_FLOAT_EQ(a, 2);
    EXPECT_FLOAT_EQ(b, 1);
}