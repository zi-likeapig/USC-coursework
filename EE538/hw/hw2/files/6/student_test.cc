#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(setDifference, empty1) {
    std::set<int> set1({});
    std::set<int> set2({});
    std::set<int> expect({});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, empty2) {
    std::set<int> set1({1,2,3});
    std::set<int> set2({});
    std::set<int> expect({1,2,3});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, empty3) {
    std::set<int> set1({});
    std::set<int> set2({1,2,3});
    std::set<int> expect({});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, empty4) {
    std::set<int> set1({1,2,3});
    std::set<int> set2({4,5,6});
    std::set<int> expect({1,2,3});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, belong1) {
    std::set<int> set1({1,2,3,4,5,6});
    std::set<int> set2({4,5,6});
    std::set<int> expect({1,2,3});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, belong2) {
    std::set<int> set1({1,2,3});
    std::set<int> set2({1,2,3,4,5,6});
    std::set<int> expect({});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

TEST(setDifference, test) {
    std::set<int> set1({-1,0,1});
    std::set<int> set2({1,2,3});
    std::set<int> expect({-1,0});
    EXPECT_EQ(setDifference(set1,set2),expect);
}

/*------------------------------------------------------------------------*/
TEST(areDisjoint, empty1) {
    std::set<int> set1({});
    std::set<int> set2({});
    EXPECT_EQ(areDisjoint(set1,set2),true);
}

TEST(areDisjoint, empty2) {
    std::set<int> set1({1,2,3});
    std::set<int> set2({});
    EXPECT_EQ(areDisjoint(set1,set2),true);
}

TEST(areDisjoint, empty3) {
    std::set<int> set1({});
    std::set<int> set2({1,2,3});
    EXPECT_EQ(areDisjoint(set1,set2),true);
}

TEST(areDisjoint, empty4) {
    std::set<int> set1({4,5,6});
    std::set<int> set2({1,2,3});
    EXPECT_EQ(areDisjoint(set1,set2),true);
}

TEST(areDisjoint, joint1) {
    std::set<int> set1({1,2,3,4,5,6});
    std::set<int> set2({1,2,3});
    EXPECT_EQ(areDisjoint(set1,set2),false);
}

TEST(areDisjoint, joint2) {
    std::set<int> set1({1,2,3});
    std::set<int> set2({1,2,3,4,5,6});
    EXPECT_EQ(areDisjoint(set1,set2),false);
}

TEST(areDisjoint, joint3) {
    std::set<int> set1({-1,0,1});
    std::set<int> set2({1,2,3,4,5,6});
    EXPECT_EQ(areDisjoint(set1,set2),false);
}