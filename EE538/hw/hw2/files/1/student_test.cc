#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(CountCharacters, Empty) {
    std::string input="";
    std::map<char,int> expect({});
    EXPECT_EQ(CountCharacters(input),expect);
}

TEST(CountCharacters, OneCharacter) {
    std::string input="/";
    std::map<char,int> expect({ {'/',1}});
    EXPECT_EQ(CountCharacters(input),expect);
}

TEST(CountCharacters, TwoCharacter) {
    std::string input="-1";
    std::map<char,int> expect({ {'-',1}, {'1',1}});
    EXPECT_EQ(CountCharacters(input),expect);
}

TEST(CountCharacters, SameCharacter) {
    std::string input="hhhhhhh h";
    std::map<char,int> expect({ {'h',8}, {' ',1}});
    EXPECT_EQ(CountCharacters(input),expect);
}

TEST(CountCharacters, UperLowerCharacter) {
    std::string input="HHhh.HHhhH";
    std::map<char,int> expect({ {'H',5}, {'h',4}, {'.',1}});
    EXPECT_EQ(CountCharacters(input),expect);
}

TEST(CountCharacters, TestCharacter) {
    std::string input="This is a test";
    std::map<char,int> expect({{'T', 1}, {'h', 1}, {'i', 2}, {'s', 3}, {' ', 3}, {'a', 1}, {'t', 2}, {'e', 1}});
    EXPECT_EQ(CountCharacters(input),expect);
}