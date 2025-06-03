#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(DoubleStackTest, Constructor) {
    DoubleStack ds;
    EXPECT_TRUE(ds.empty());
    EXPECT_EQ(ds.size(), 0);
}

TEST(DoubleStackTest, Push) {
    DoubleStack ds;
    ds.push(2); // Even stack: {2}
    ds.push(3); // Odd stack: {3}
    EXPECT_FALSE(ds.empty());
    EXPECT_EQ(ds.size(), 2);
    EXPECT_EQ(ds.top(), 3);
}

TEST(DoubleStackTest, PopDifferentValues) {
    DoubleStack ds;
    ds.push(4);  // Even stack: {4}
    ds.push(3);  // Odd stack: {3}

    ds.pop();  // removes 4

    EXPECT_EQ(ds.top(), 3);
    EXPECT_EQ(ds.size(), 1);
}

TEST(DoubleStackTest, PopSameValues) {
    DoubleStack ds;
    ds.push(8);  // Even stack: {8}
    ds.push(8);  // Even stack: {8, 8}

    ds.pop();  // Even stack: {8}
    EXPECT_FALSE(ds.empty());

    ds.pop();  // empty
    EXPECT_TRUE(ds.empty());
}

TEST(DoubleStackTest, PopOneStackEmpty) {
    DoubleStack ds;
    ds.push(6);  // Even stack: {6}
    ds.pop();  // remove 6

    EXPECT_TRUE(ds.empty());
}

TEST(DoubleStackTest, Top) {
    DoubleStack ds;
    EXPECT_EQ(ds.top(), -1);

    ds.push(10);
    EXPECT_EQ(ds.top(), 10);

    ds.push(5);
    EXPECT_EQ(ds.top(), 10);

    ds.pop();
    EXPECT_EQ(ds.top(), 5);
}

TEST(DoubleStackTest, Size) {
    DoubleStack ds;
    EXPECT_EQ(ds.size(), 0);

    ds.push(2);
    ds.push(3);
    EXPECT_EQ(ds.size(), 2);

    ds.pop();
    EXPECT_EQ(ds.size(), 1);
}


