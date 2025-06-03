#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(HikerPathTest, SimpleMaze) {
    vector<vector<int>> maze = {//
                                {0, 0, 0, 1},
                                {0, 1, 0, 1},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0}};
  
    vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
                                        {2, 2}, {2, 3}, {3, 3}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, allok) {
    vector<vector<int>> maze = {//
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
  
    vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {0, 3},
                                        {1, 3}, {2, 3}, {3, 3}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, notok_start) {
    vector<vector<int>> maze = {//
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 1}};
  
    vector<vector<int>> expectedPath = {{-1, -1}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, notok_end) {
    vector<vector<int>> maze = {//
                                {1, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
  
    vector<vector<int>> expectedPath = {{-1, -1}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, up) {
    vector<vector<int>> maze = {
                                {0, 1, 1, 1, 1},
                                {0, 1, 0, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 1, 0}};
  
    vector<vector<int>> expectedPath = {{0, 0}, {1, 0}, {2, 0}, {3, 0},
                                        {3, 1}, {3, 2}, {2, 2}, {1, 2},
                                        {1, 3}, {1, 4}, {2, 4}, {3, 4}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, notok1) {
    vector<vector<int>> maze = {//
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 1},
                                {0, 0, 1, 0}};
  
    vector<vector<int>> expectedPath = {{-1, -1}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, notok2) {
    vector<vector<int>> maze = {//
                                {0, 1, 1, 1},
                                {0, 0, 0, 0},
                                {0, 1, 1, 1},
                                {0, 0, 0, 0}};
  
    vector<vector<int>> expectedPath = {{0, 0}, {1, 0}, {2, 0}, {3, 0},
                                        {3, 1}, {3, 2}, {3, 3}};
    vector<vector<int>> actualPath = HikerPath(maze);
  
    EXPECT_EQ(expectedPath, actualPath);
}
