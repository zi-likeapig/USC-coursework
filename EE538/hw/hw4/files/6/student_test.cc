#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(NumConnectedComponents, test1) {
    vector<vector<char>> maze = {
                                {'0', '0', '0', '1'},
                                {'0', '1', '0', '1'},
                                {'0', '1', '0', '0'},
                                {'0', '0', '1', '0'}};
  
    EXPECT_EQ(NumConnectedComponents(maze), 3);
}

TEST(NumConnectedComponents, teat2) {
    vector<vector<char>> maze = {
                                {'0', '0', '0', '1'},
                                {'0', '1', '0', '1'},
                                {'0', '1', '0', '0'},
                                {'0', '1', '1', '0'}};
    EXPECT_EQ(NumConnectedComponents(maze), 2);
}

TEST(NumConnectedComponents, allnot) {
    vector<vector<char>> maze = {
                                {'0', '0', '0', '0'},
                                {'0', '0', '0', '0'},
                                {'0', '0', '0', '0'},
                                {'0', '0', '0', '0'}};
    EXPECT_EQ(NumConnectedComponents(maze), 0);
}

TEST(NumConnectedComponents, allok) {
    vector<vector<char>> maze = {
                                {'1', '1', '1', '1'},
                                {'1', '1', '1', '1'},
                                {'1', '1', '1', '1'},
                                {'1', '1', '1', '1'}};
    EXPECT_EQ(NumConnectedComponents(maze), 1);
}

TEST(NumConnectedComponents, empty) {
    vector<vector<char>> maze = {};
    EXPECT_EQ(NumConnectedComponents(maze), 0);
}