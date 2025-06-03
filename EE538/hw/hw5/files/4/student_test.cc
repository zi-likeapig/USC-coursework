#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "q.h"

const int INF = INT_MAX;

// TODO: Add more tests below!

Graph CreateTestGraph() {
    std::map<int, std::set<std::pair<int, int>>> weight_map = {
        {0, {{1, 4}, {2, 1}}},
        {1, {{3, 1}}},
        {2, {{1, 2}, {3, 5}}},
        {3, {}}
    };
    return Graph(weight_map);
}
  
TEST(GraphTest, GetPredecessors) {
    Graph g = CreateTestGraph();
    auto preds = g.GetPredecessors();
    
    EXPECT_EQ(preds[0].size(), 0);
    EXPECT_EQ(preds[1], std::set<int>({0, 2}));
    EXPECT_EQ(preds[2], std::set<int>({0}));
    EXPECT_EQ(preds[3], std::set<int>({1, 2}));
}
  
TEST(GraphTest, GetEdges) {
    Graph g = CreateTestGraph();
    auto edges = g.GetEdges();
    
    std::set<std::pair<int, int>> expected = {
        {0, 1}, {0, 2}, {1, 3}, {2, 1}, {2, 3}
    };
    EXPECT_EQ(edges, expected);
}
  
TEST(GraphTest, GetWeight) {
    Graph g = CreateTestGraph();
    
    EXPECT_EQ(g.GetWeight(0, 1), 4);
    EXPECT_EQ(g.GetWeight(0, 2), 1);
    EXPECT_EQ(g.GetWeight(1, 3), 1);
    EXPECT_EQ(g.GetWeight(2, 1), 2);
    EXPECT_EQ(g.GetWeight(2, 3), 5);
    
    EXPECT_EQ(g.GetWeight(3, 0), INT_MAX);
}
  

TEST(GraphTest, GetMinWeight) {
    Graph g = CreateTestGraph();
    EXPECT_EQ(g.GetMinWeight(), 1);
}
  

TEST(GraphTest, Dijkstra) {
    Graph g = CreateTestGraph();
    auto dists = g.Dijkstra(0);
    
    std::vector<long> expected = {0, 3, 1, 4};
    EXPECT_EQ(dists, expected);
}
  

TEST(GraphTest, BellmanFord) {
    Graph g = CreateTestGraph();
    auto dists = g.BellmanFord(0);
    
    std::vector<long> expected = {0, 3, 1, 4};
    EXPECT_EQ(dists, expected);
}
  
/* // (可选) 测试负边图 Bellman-Ford
TEST(GraphTest, BellmanFordWithNegativeEdges) {
    std::map<int, std::set<std::pair<int, int>>> weight_map = {
        {0, {{1, 1}}},
        {1, {{2, -1}}},
        {2, {{3, -1}}},
        {3, {{0, -1}}}
    };
    Graph g(weight_map);
    auto dists = g.BellmanFord(0);
    
    // 这里不检测是否有负环，只测试算法是否正确防止崩溃
    EXPECT_EQ(dists.size(), 4);
}*/

Graph CreateNegativeEdgeGraph() {
    std::map<int, std::set<std::pair<int, int>>> weight_map = {
        {0, {{1, 4}, {2, 5}}},
        {1, {{2, -3}, {3, 6}}},
        {2, {{3, 2}}},
        {3, {}}
    };
    return Graph(weight_map);
}
  
TEST(GraphTest, BellmanFordNegativeEdge) {
    Graph g = CreateNegativeEdgeGraph();
    auto dists = g.BellmanFord(0);
  
    // 0 -> 0 = 0
    // 0 -> 1 = 4
    // 0 -> 2 = 1 (0->1->2, 4 + (-3))
    // 0 -> 3 = 3 (0->1->2->3, 4 + (-3) + 2)
    std::vector<long> expected = {0, 4, 1, 3};
    
    EXPECT_EQ(dists, expected);
}


//********************************************************************** */
template <class T>
void PrintCollection(T& input, int numberOfSpaces = 0) {
  for (int i = 0; i < numberOfSpaces; i++) {
    std::cout << " ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    if (n == INF) {
      std::cout << "INF";
    } else {
      std::cout << n;
    }
    if (count < input.size()) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}

template <class T>
void Print2dVector(std::vector<std::vector<T>> input) {
  std::cout << "{ " << std::endl;
  for (auto e : input) {
    PrintCollection(e, /*numberOfSpaces=*/2);
  }
  std::cout << " }" << std::endl;
}

std::map<int, std::set<std::pair<int, int>>> ConvertToWeightMap(
    std::vector<std::vector<int>> adjacency_matrix) {
  std::map<int, std::set<std::pair<int, int>>> weight_map;
  for (int i = 0; i < adjacency_matrix.size(); i++) {
    weight_map[i] = std::set<std::pair<int, int>>();
    for (int j = 0; j < adjacency_matrix.size(); j++) {
      if (i != j && adjacency_matrix[i][j] != INF) {
        weight_map[i].insert(std::make_pair(j, adjacency_matrix[i][j]));
      }
    }
  }
  return weight_map;
}

const std::vector<std::vector<int>> graph1{
    {0, INF, INF, INF},  // 0
    {INF, 0, INF, INF},  // 1
    {INF, INF, 0, INF},  // 2
    {INF, INF, INF, 0},  // 3
};

const std::vector<std::vector<int>> graph2{
    {0, 1000, 20, 35},  // 0
    {40, 0, 30, 10},    // 1
    {20, 30, 0, 30},    // 2
    {35, 10, 30, 0},    // 3
};

const std::vector<std::vector<int>> graph3 = {
    {0, 4, 2, INF, INF, INF},        // 0
    {INF, 0, 5, 10, INF, INF},       // 1
    {INF, INF, 0, INF, 3, INF},      // 2
    {INF, INF, INF, 0, INF, 11},     // 3
    {INF, INF, INF, 4, 0, INF},      // 4
    {INF, INF, INF, INF, INF, INF},  // 5
};

std::vector<std::vector<int>> graph4{
    {0, 4, INF, INF, INF, INF, INF, 8, INF},   // 0
    {4, 0, 8, INF, INF, INF, INF, 11, INF},    // 1
    {INF, 8, 0, 7, INF, 4, INF, INF, 2},       // 2
    {INF, INF, 7, 0, 9, 14, INF, INF, INF},    // 3
    {INF, INF, INF, 9, 0, 10, INF, INF, INF},  // 4
    {INF, INF, 4, 14, 10, 0, 2, INF, INF},     // 5
    {INF, INF, INF, INF, INF, 2, 0, 1, 6},     // 6
    {8, 11, INF, INF, INF, INF, 1, 0, 7},      // 7
    {INF, INF, 2, INF, INF, INF, 6, 7, 0}      // 8
};

const std::vector<std::vector<int>> graph5 = {
    {0, 4, -1, INF, INF, INF},        // 0
    {INF, 0, 5, 10, INF, INF},       // 1
    {INF, INF, 0, INF, 3, INF},      // 2
    {INF, INF, INF, 0, INF, 11},     // 3
    {INF, INF, INF, 4, 0, INF},      // 4
    {INF, INF, INF, INF, INF, INF},  // 5
};
//-----------------------------------------------------------------------------

TEST(Dijkstra, Graph1) {
  // distances is only used for printing in the test log.
  auto distances = graph1;
  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  // std::map<int, std::set<std::pair<int, int>>> weight_map{
  //     {{0, {}}, {1, {}}, {2, {}}, {3, {}}}};

  std::vector<std::vector<long>> expected = {
      {0, INF, INF, INF},  // 0
      {INF, 0, INF, INF},  // 1
      {INF, INF, 0, INF},  // 2
      {INF, INF, INF, 0},  // 3
  };

  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.Dijkstra(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}

TEST(Dijkstra, Graph2) {
  // distances is only used for printing in the test log.
  auto distances = graph2;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);

  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 45, 20, 35},  // 0
      {40, 0, 30, 10},  // 1
      {20, 30, 0, 30},  // 2
      {35, 10, 30, 0}   // 3
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.Dijkstra(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}

TEST(Dijkstra, Graph3) {
  // distances is only used for printing in the test log.
  auto distances = graph3;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 4, 2, 9, 5, 20},          // 0
      {INF, 0, 5, 10, 8, 21},       // 1
      {INF, INF, 0, 7, 3, 18},      // 2
      {INF, INF, INF, 0, INF, 11},  // 3
      {INF, INF, INF, 4, 0, 15},    // 4
      {INF, INF, INF, INF, INF, 0}  // 5
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.Dijkstra(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}

TEST(Dijkstra, Graph4) {
  // distances is only used for printing in the test log.
  auto distances = graph4;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 4, 12, 19, 21, 11, 9, 8, 14},    // 0
      {4, 0, 8, 15, 22, 12, 12, 11, 10},   // 1
      {12, 8, 0, 7, 14, 4, 6, 7, 2},       // 2
      {19, 15, 7, 0, 9, 11, 13, 14, 9},    // 3
      {21, 22, 14, 9, 0, 10, 12, 13, 16},  // 4
      {11, 12, 4, 11, 10, 0, 2, 3, 6},     // 5
      {9, 12, 6, 13, 12, 2, 0, 1, 6},      // 6
      {8, 11, 7, 14, 13, 3, 1, 0, 7},      // 7
      {14, 10, 2, 9, 16, 6, 6, 7, 0}       // 8
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.Dijkstra(i);

    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}
//-----------------------------------------------------------------------------
TEST(Predecessors, Graph1) {
  // distances is only used for printing in the test log.
  auto distances = graph1;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::map<int, std::set<int>> expected = {{0, {}}, {1, {}}, {2, {}}, {3, {}}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetPredecessors();

  EXPECT_EQ(expected, actual);
}

TEST(Predecessors, Graph2) {
  // distances is only used for printing in the test log.
  auto distances = graph2;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::map<int, std::set<int>> expected = {
      {0, {1, 2, 3}}, {1, {0, 2, 3}}, {2, {0, 1, 3}}, {3, {0, 1, 2}}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetPredecessors();

  EXPECT_EQ(expected, actual);
}

TEST(Predecessors, Graph3) {
  // distances is only used for printing in the test log.
  auto distances = graph3;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::map<int, std::set<int>> expected = {{//
                                            {0, {}},
                                            {1, {0}},
                                            {2, {0, 1}},
                                            {3, {1, 4}},
                                            {4, {2}},
                                            {5, {3}}}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetPredecessors();

  EXPECT_EQ(expected, actual);
}

TEST(Predecessors, Graph4) {
  // distances is only used for printing in the test log.
  auto distances = graph4;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::map<int, std::set<int>> expected = {
      //
      {0, {1, 7}},    {1, {0, 2, 7}},    {2, {1, 3, 5, 8}},
      {3, {2, 4, 5}}, {4, {3, 5}},       {5, {2, 3, 4, 6}},
      {6, {5, 7, 8}}, {7, {0, 1, 6, 8}}, {8, {2, 6, 7}}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetPredecessors();

  EXPECT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(GetEdges, Graph1) {
  // distances is only used for printing in the test log.
  auto distances = graph1;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::set<std::pair<int, int>> expected = {};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetEdges();

  EXPECT_EQ(expected, actual);
}

TEST(GetEdges, Graph2) {
  // distances is only used for printing in the test log.
  auto distances = graph2;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::set<std::pair<int, int>> expected = {{0, 1}, {0, 2}, {0, 3}, {1, 0},
                                            {1, 2}, {1, 3}, {2, 0}, {2, 1},
                                            {2, 3}, {3, 0}, {3, 1}, {3, 2}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetEdges();

  EXPECT_EQ(expected, actual);
}

TEST(GetEdges, Graph3) {
  // distances is only used for printing in the test log.
  auto distances = graph3;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  std::set<std::pair<int, int>> expected = {{0, 1}, {0, 2}, {1, 2}, {1, 3},
                                            {2, 4}, {3, 5}, {4, 3}};

  auto weight_map = ConvertToWeightMap(distances);
  Graph g(weight_map);

  auto actual = g.GetEdges();

  EXPECT_EQ(expected, actual);
}


//-----------------------------------------------------------------------------

TEST(BellmanFord, Graph1) {
  // distances is only used for printing in the test log.
  auto distances = graph1;
  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, INF, INF, INF},  // 0
      {INF, 0, INF, INF},  // 1
      {INF, INF, 0, INF},  // 2
      {INF, INF, INF, 0},  // 3
  };

  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.BellmanFord(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}

TEST(BellmanFord, Graph2) {
  // distances is only used for printing in the test log.
  auto distances = graph2;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);

  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 45, 20, 35},  // 0
      {40, 0, 30, 10},  // 1
      {20, 30, 0, 30},  // 2
      {35, 10, 30, 0}   // 3
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.BellmanFord(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}

TEST(BellmanFord, Graph3) {
  // distances is only used for printing in the test log.
  auto distances = graph3;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 4, 2, 9, 5, 20},          // 0
      {INF, 0, 5, 10, 8, 21},       // 1
      {INF, INF, 0, 7, 3, 18},      // 2
      {INF, INF, INF, 0, INF, 11},  // 3
      {INF, INF, INF, 4, 0, 15},    // 4
      {INF, INF, INF, INF, INF, 0}  // 5
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.BellmanFord(i);
    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}


TEST(BellmanFord, Graph5) {
  // distances is only used for printing in the test log.
  auto distances = graph5;

  std::cout << "Graph weight matrix: " << std::endl;
  Print2dVector(distances);
  auto weight_map = ConvertToWeightMap(distances);

  std::vector<std::vector<long>> expected = {
      {0, 4, -1, 6, 2, 17},          // 0
      {INF, 0, 5, 10, 8, 21},       // 1
      {INF, INF, 0, 7, 3, 18},      // 2
      {INF, INF, INF, 0, INF, 11},  // 3
      {INF, INF, INF, 4, 0, 15},    // 4
      {INF, INF, INF, INF, INF, 0}  // 5
  };
  for (int i = 0; i < expected.size(); i++) {
    Graph g(weight_map);
    auto actual = g.BellmanFord(i);

    EXPECT_EQ(expected[i], actual) << "(Error happened when node " << i
                                   << " was the source.)" << std::endl;
  }
}