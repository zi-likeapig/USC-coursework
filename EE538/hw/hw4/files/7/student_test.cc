#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(DFSTest, EmptyGraph) {
    std::map<int, std::vector<int>> adj;
    std::vector<int> result = DFS(0, adj);
    std::vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(DFSTest, LinearGraph) {
    std::map<int, std::vector<int>> adj = {
        {0, {1}},
        {1, {2}},
        {2, {3}},
        {3, {}}
    };
    std::vector<int> result = DFS(0, adj);
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(result, expected);
}

TEST(DFSTest, BranchingGraph) {
    std::map<int, std::vector<int>> adj = {
        {0, {1, 2}},
        {1, {3}},
        {2, {}},
        {3, {}}
    };
    std::vector<int> result = DFS(0, adj);
    std::vector<int> expected1 = {0, 1, 2, 3};
    EXPECT_TRUE(result == expected1);
}

TEST(DFSTest, CyclicGraph) {
    std::map<int, std::vector<int>> adj = {
        {0, {1}},
        {1, {2}},
        {2, {0}}
    };
    std::vector<int> result = DFS(0, adj);
    std::vector<int> expected = {0, 1, 2};
    EXPECT_EQ(result, expected);
}

TEST(DFSTest, StartNodeNotInAdjList) {
    std::map<int, std::vector<int>> adj = {
        {0, {}},
        {1, {2}},
        {2, {3}},
        {3, {}}
    };
    std::vector<int> result = DFS(0, adj);
    std::vector<int> expected = {0};
    EXPECT_EQ(result, expected);
}