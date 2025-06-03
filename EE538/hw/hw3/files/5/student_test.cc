#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CheckValidExpression, test) {
    CPPLib c;
    std::string input="(a+b)[c*d]{5g+h}";
    EXPECT_TRUE(c.CheckValidExpression(input));

    input="(7h+[5c)+7]";
    EXPECT_FALSE(c.CheckValidExpression(input));

    input=")7h+[5c]+7)";
    EXPECT_FALSE(c.CheckValidExpression(input));
}

TEST(IsPalindrome, test) {
    CPPLib c;
    std::string input="(11)";
    EXPECT_FALSE(c.IsPalindrome(input));

    input="(11(";
    EXPECT_TRUE(c.IsPalindrome(input));

    input="abbca";
    EXPECT_FALSE(c.IsPalindrome(input));

    input="vnmnv";
    EXPECT_TRUE(c.IsPalindrome(input));
}

TEST(OddChar, test) {
    CPPLib c;
    std::string input="(11_(";
    EXPECT_EQ(c.OddChar(input),static_cast<int>('_'));

    input="abbca";
    EXPECT_EQ(c.OddChar(input),static_cast<int>('c'));

    input="vnmnmmv";
    EXPECT_EQ(c.OddChar(input),static_cast<int>('m'));
}
