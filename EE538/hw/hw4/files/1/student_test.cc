#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(FindNumberOfUniquePaths, SingleRow_AllOnes) {
    std::vector<std::vector<int>> grid = {{1, 1, 1}};
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {0, 2}), 1);
}

TEST(FindNumberOfUniquePaths, SingleCol_AllOnes) {
    std::vector<std::vector<int>> grid = {{1}, {1}, {1}};
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {2, 0}), 1);
}

TEST(FindNumberOfUniquePaths, SingleRow_WithZero) {
    std::vector<std::vector<int>> grid = {{1, 0, 1}};
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {0, 2}), 0);
}

TEST(FindNumberOfUniquePaths, TwoByThree_AllOnes) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1}
    };
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {1, 2}), 3);
}

TEST(FindNumberOfUniquePaths, TwoByThree_AllOnes_startmove) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1}
    };
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {1, 0}, {1, 2}), 1);
}

TEST(FindNumberOfUniquePaths, TwoByThree_WithBlock) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1},
        {1, 0, 1}
    };
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {1, 2}), 1);
}

TEST(FindNumberOfUniquePaths, start_is_block) {
    std::vector<std::vector<int>> grid = {
        {0, 1, 1},
    };
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {0, 2}), 0);
}

TEST(FindNumberOfUniquePaths, end_is_block) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 0},
    };
    EXPECT_EQ(FindNumberOfUniquePaths(grid, {0, 0}, {0, 2}), 0);
}