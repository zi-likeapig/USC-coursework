#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <climits>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(GraphTest, DFSBasic) {
    std::map<int, std::set<int>> adj = {
      {0, {1, 2}},
      {1, {3}},
      {2, {3}},
      {3, {}}
    };
    Graph g(adj);
    std::vector<int> result = g.DFS(0);
    std::vector<int> expected = {0, 1, 3, 2};
    EXPECT_EQ(result, expected);

    result = g.DFS(1);
    expected = {1, 3};
    EXPECT_EQ(result, expected);

    result = g.DFS(3);
    expected = {3};
    EXPECT_EQ(result, expected);
}
  
TEST(GraphTest, DFSAllWithDisconnectedGraph) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {}},
      {2, {3}},
      {3, {}}
    };
    Graph g(adj);
    std::vector<int> visited = g.DFSAll();
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(visited.size(), 4);
    EXPECT_EQ(visited, expected);
    EXPECT_TRUE(std::find(visited.begin(), visited.end(), 0) != visited.end());
    EXPECT_TRUE(std::find(visited.begin(), visited.end(), 2) != visited.end());
}

TEST(GraphTest, DFSempty) {
    std::map<int, std::set<int>> adj = {};
    Graph g(adj);
    std::vector<int> visited = g.DFSAll();
    std::vector<int> expected = {};
    EXPECT_EQ(visited, expected);
}

TEST(GraphTest, DFSnot_ordered) {
    std::map<int, std::set<int>> adj = {
      {0, {4,1}},
      {1, {}},
      {2, {3}},
      {3, {}},
      {4, {3}}
    };
    Graph g(adj);
    std::vector<int> visited = g.DFSAll();
    std::vector<int> expected = {0, 1, 4, 3, 2};
    EXPECT_EQ(visited.size(), 5);
    EXPECT_EQ(visited, expected);
    EXPECT_TRUE(std::find(visited.begin(), visited.end(), 0) != visited.end());
    EXPECT_TRUE(std::find(visited.begin(), visited.end(), 2) != visited.end());
}
  
TEST(GraphTest, BFSBasic) {
    std::map<int, std::set<int>> adj = {
      {0, {1, 2}},
      {1, {3}},
      {2, {3}},
      {3, {}}
    };
    Graph g(adj);
    BFSReturnValue result = g.BFS(0);
    std::vector<int> expected_visited = {0, 1, 2, 3};
    std::vector<int> expected_distance = {0, 1, 1, 2};
  
    EXPECT_EQ(result.visited, expected_visited);
    for (int i = 0; i < expected_distance.size(); ++i) {
        EXPECT_EQ(result.distance[i], expected_distance[i]);
    }
  
    EXPECT_EQ(result.path[3], std::vector<int>({0, 1, 3}));
}

TEST(GraphTest, BFS_notConnected1) {
    std::map<int, std::set<int>> adj = {
      {0, {1, 2}},
      {1, {3}},
      {2, {3}},
      {3, {}},
      {5, {7}},
      {6, {}},
      {7, {0}}
    };
    Graph g(adj);
    BFSReturnValue result = g.BFS(0);
    std::vector<int> expected_visited = {0, 1, 2, 3};
    std::vector<int> expected_distance = {0, 1, 1, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    EXPECT_EQ(result.visited, expected_visited);
    for (int i = 0; i < expected_distance.size(); ++i) {
        EXPECT_EQ(result.distance[i], expected_distance[i]);
    }
    EXPECT_EQ(result.path[0], std::vector<int>({0}));
    EXPECT_EQ(result.path[1], std::vector<int>({0, 1}));
    EXPECT_EQ(result.path[2], std::vector<int>({0, 2}));
    EXPECT_EQ(result.path[3], std::vector<int>({0, 1, 3}));
    EXPECT_EQ(result.path[4], std::vector<int>({}));
    EXPECT_EQ(result.path[5], std::vector<int>({}));
    EXPECT_EQ(result.path[6], std::vector<int>({}));
    EXPECT_EQ(result.path[7], std::vector<int>({}));
}

TEST(GraphTest, BFS_notConnected2) {
    std::map<int, std::set<int>> adj = {
      {0, {1, 2}},
      {1, {3}},
      {2, {3}},
      {3, {}},
      {5, {7}},
      {6, {}},
      {7, {0}}
    };
    Graph g(adj);
    BFSReturnValue result = g.BFS(5);
    std::vector<int> expected_visited = {5, 7, 0, 1, 2, 3};
    std::vector<int> expected_distance = {2, 3, 3, 4, INT_MAX, 0, INT_MAX, 1};
    EXPECT_EQ(result.visited, expected_visited);
    for (int i = 0; i < expected_distance.size(); ++i) {
        EXPECT_EQ(result.distance[i], expected_distance[i]);
    }
    EXPECT_EQ(result.path[0], std::vector<int>({5, 7, 0}));
    EXPECT_EQ(result.path[1], std::vector<int>({5, 7, 0, 1}));
    EXPECT_EQ(result.path[2], std::vector<int>({5, 7, 0, 2}));
    EXPECT_EQ(result.path[3], std::vector<int>({5, 7, 0, 1, 3}));
    EXPECT_EQ(result.path[4], std::vector<int>({}));
    EXPECT_EQ(result.path[5], std::vector<int>({5}));
    EXPECT_EQ(result.path[6], std::vector<int>({}));
    EXPECT_EQ(result.path[7], std::vector<int>({5, 7}));
}

TEST(GraphTest, BFS_notContinue) {
    std::map<int, std::set<int>> adj = {
      {0, {4, 3}},
      {3, {2}},
      {4, {2}},
      {2, {}}
    };
    Graph g(adj);
    BFSReturnValue result = g.BFS(0);
    std::vector<int> expected_visited = {0, 3, 4, 2};
    std::vector<int> expected_distance = {0, INT_MAX, 2, 1, 1};
  
    EXPECT_EQ(result.visited, expected_visited);
    for (int i = 0; i < expected_distance.size(); ++i) {
        EXPECT_EQ(result.distance[i], expected_distance[i]);
    }
    EXPECT_EQ(result.path[0], std::vector<int>({0}));
    EXPECT_EQ(result.path[1], std::vector<int>({}));
    EXPECT_EQ(result.path[2], std::vector<int>({0, 3, 2}));
    EXPECT_EQ(result.path[3], std::vector<int>({0, 3}));
    EXPECT_EQ(result.path[4], std::vector<int>({0, 4}));
}

  
TEST(GraphTest, PathBetweenNodes) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.IsPathBetweenNodes(0, 2));
    EXPECT_FALSE(g.IsPathBetweenNodes(2, 0));
    EXPECT_TRUE(g.IsPathBetweenNodes(2, 2));
}

TEST(GraphTest, IsBidirectional_true) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2, 0}},
      {2, {1}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(GraphTest, IsBidirectional_false) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {1}}
    };
    Graph g(adj);
    EXPECT_FALSE(g.IsBidirectional());
}

TEST(GraphTest, IsBidirectional_empty) {
    std::map<int, std::set<int>> adj = {};
    Graph g(adj);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(GraphTest, IsBidirectional_oneNode) {
    std::map<int, std::set<int>> adj = {
      {0, {}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.IsBidirectional());
}

TEST(GraphTest, IsConnected_true) {
    std::map<int, std::set<int>> adj = {
        {0, {1}},
        {1, {2}},
        {2, {}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.IsConnected());
}

TEST(GraphTest, IsConnected_false) {
    std::map<int, std::set<int>> adj = {
        {0, {1}},
        {1, {0}},
        {2, {3}},
        {3, {}}
    };
    Graph g(adj);
    EXPECT_FALSE(g.IsConnected());
}

TEST(GraphTest, IsConnected_oneNode) {
    std::map<int, std::set<int>> adj = {
        {0, {}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.IsConnected());
}

TEST(GraphTest, HasCycleFalse) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {}}
    };
    Graph g(adj);
    EXPECT_FALSE(g.HasCycle());
}
  
TEST(GraphTest, HasCycleTrue) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {0}}  // cycle
    };
    Graph g(adj);
    EXPECT_TRUE(g.HasCycle());
}
  
TEST(GraphTest, ReachesCycleTrue) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {1}},  // 1 -> 2 -> 1 cycle
      {3, {4}},
      {4, {}}
    };
    Graph g(adj);
    EXPECT_TRUE(g.ReachesACycle(0));
    EXPECT_TRUE(g.ReachesACycle(1));
    EXPECT_TRUE(g.ReachesACycle(2));
    EXPECT_FALSE(g.ReachesACycle(3));
    EXPECT_FALSE(g.ReachesACycle(4));
}
  
TEST(GraphTest, ReachesCycleFalse) {
    std::map<int, std::set<int>> adj = {
      {0, {1}},
      {1, {2}},
      {2, {}}
    };
    Graph g(adj);
    EXPECT_FALSE(g.ReachesACycle(0));
}