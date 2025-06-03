#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CanBecomeTest, Empty1) {
    int actual = CanBecome("a", "");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, Empty2) {
    int actual = CanBecome("", "2");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, Empty3) {
    int actual = CanBecome("", ""); 
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, One) {
    int actual = CanBecome("/", "/");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, Test1) { 
    int actual = CanBecome("12345", "54321");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, Test2) {
    int actual = CanBecome("12345a", "5a1234");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, Test3) {
    int actual = CanBecome("abcdabefab", "abefababcd");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, Test4) {
    int actual = CanBecome("1qa/", "qa/1");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, Test5) {
    int actual = CanBecome("1qa/", "qa/12");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, Test6) {
    int actual = CanBecome("abcdabefab", "abcdababcd");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, Test7) {
    int actual = CanBecome("hello world", " worldhello");
    EXPECT_EQ(1, actual); 
}