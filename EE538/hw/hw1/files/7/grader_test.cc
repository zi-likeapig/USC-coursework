#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------s
TEST(CanBecomeTest, TestCase1) { 
    int actual = CanBecome("abcde", "cdeab");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, TestCase2) {
    int actual = CanBecome("abcde", "abced");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, TestCase3) {
    int actual = CanBecome("abcde", "abcde");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, TestCase4) {
    int actual = CanBecome("a", "a");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, TestCase5) {
    int actual = CanBecome("abcde", "abcdea");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, TestCase6) {
    int actual = CanBecome("a", "");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, TestCase7) {
    int actual = CanBecome("", "a");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, TestCase8) {
    int actual = CanBecome("", ""); 
    EXPECT_EQ(1, actual); 
}