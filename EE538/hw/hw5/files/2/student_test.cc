#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"
using ::testing::Combine;
using ::testing::Values;
using ::testing::ValuesIn;

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------


TEST(KnapSackTest, BasicCase) {
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> values = {6, 10, 12};
    int capacity = 5;
    // pick 1 and 2，sum_val = 22
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 22);
}

TEST(KnapSackTest, SmallCapacity) {
    std::vector<int> weights = {2, 3, 4};
    std::vector<int> values = {3, 4, 5};
    int capacity = 1;
    // none
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 0);
}

TEST(KnapSackTest, ExactFitOneItem1) {
    std::vector<int> weights = {2, 3, 4};
    std::vector<int> values = {3, 4, 5};
    int capacity = 4;
    // pick 3，sum_val = 5
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 5);
}

TEST(KnapSackTest, ExactFitOneItem2) {
    std::vector<int> weights = {2, 3, 4};
    std::vector<int> values = {3, 10, 5};
    int capacity = 4;
    // pick 2，sum_val = 10
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 10);
}

TEST(KnapSackTest, EmptyInput) {
    std::vector<int> weights = {};
    std::vector<int> values = {};
    int capacity = 10;
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 0);
}

TEST(KnapSackTest, ZeroCapacity) {
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> values = {6, 10, 12};
    int capacity = 0;
    EXPECT_EQ(knapSack01NoDynamicProgramming(weights, values, capacity), 0);
}




TEST(KnapSackMemoTest, BasicCase) {
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> values = {6, 10, 12};
    int capacity = 5;
    EXPECT_EQ(knapSack01Memo(weights, values, capacity), 22);
}

TEST(KnapSackMemoTest, SmallCapacity) {
    std::vector<int> weights = {2, 3, 4};
    std::vector<int> values = {3, 4, 5};
    int capacity = 1;
    EXPECT_EQ(knapSack01Memo(weights, values, capacity), 0);
}

TEST(KnapSackMemoTest, ImpossibleToFit) {
    std::vector<int> weights = {5, 6, 7};
    std::vector<int> values = {10, 60, 30};
    int capacity = 7;
    EXPECT_EQ(knapSack01Memo(weights, values, capacity), 60);
}




TEST(KnapSackTablulationTest, BasicCase) {
    std::vector<int> weights = {1, 2, 3};
    std::vector<int> values = {6, 10, 12};
    int capacity = 5;
    EXPECT_EQ(knapSack01Tablulation(weights, values, capacity), 22);
}

TEST(KnapSackTablulationTest, SmallCapacity) {
    std::vector<int> weights = {2, 3, 4};
    std::vector<int> values = {3, 4, 5};
    int capacity = 1;
    EXPECT_EQ(knapSack01Tablulation(weights, values, capacity), 0);
}

TEST(KnapSackTablulationTest, ImpossibleToFit) {
    std::vector<int> weights = {5, 6, 7};
    std::vector<int> values = {10, 60, 30};
    int capacity = 7;
    EXPECT_EQ(knapSack01Tablulation(weights, values, capacity), 60);
}

TEST(KnapSackTest, MemoVsTablulationConsistency) {
    std::vector<int> weights = {3, 4, 5};
    std::vector<int> values = {30, 50, 60};
    int capacity = 8;
    EXPECT_EQ(knapSack01Memo(weights, values, capacity),
              knapSack01Tablulation(weights, values, capacity));
}



//******************************************************************** */
template <class T>
void PrintCollection(T &input, int numberOfSpaces = 0) {
  for (int i = 0; i < numberOfSpaces; i++) {
    std::cout << " ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;

    std::cout << n;

    if (count < input.size()) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
using KnapsackInputType =
    std::tuple<std::vector<int>, std::vector<int>, int, int>;

std::map<std::string, KnapsackInputType> input_map = {
    // Since we are using counting sort, all inputs should be non-negative
    // integers.
    {"Case1",
     KnapsackInputType{//
                       /*values=*/std::vector<int>{60, 100, 120},
                       /*weights=*/std::vector<int>{10, 20, 30}, /*W=*/50,
                       /*expected*=*/220}},
    {"Case2",
     KnapsackInputType{//
                       /*values=*/std::vector<int>{1, 2, 2, 4, 10},
                       /*weights=*/std::vector<int>{1, 2, 1, 12, 4}, /*W=*/15,
                       /*expected*=*/15}},
    {"Case3",
     KnapsackInputType{//
                       /*values=*/std::vector<int>{1, 10, 15, 20},
                       /*weights=*/std::vector<int>{1, 10, 15, 15}, /*W=*/26,
                       /*expected*=*/31}},

    //
};

std::map<std::string, std::function<int(const std::vector<int> &,
                                        const std::vector<int> &, int)>>
    function_map = {
        //
        {"knapSack01NoDynamicProgramming", knapSack01NoDynamicProgramming},
        {"knapSack01Memo", knapSack01Memo},
        {"knapSack01Tablulation", knapSack01Tablulation}
        //
};

class Tester : public testing::TestWithParam<std::tuple<
                   std::pair<const std::string,
                             std::function<int(const std::vector<int> &,
                                               const std::vector<int> &, int)>>,
                   std::pair<const std::string, KnapsackInputType>>> {};

INSTANTIATE_TEST_SUITE_P(
    Knapsack, Tester, Combine(ValuesIn(function_map), ValuesIn(input_map)),
    [](const testing::TestParamInfo<Tester::ParamType> &info) {
      return std::get<0>(info.param).first + "_" +
             std::get<1>(info.param).first;
    });

TEST_P(Tester, test) {
  auto p = GetParam();

  auto f = std::get<0>(p).second;
  auto values = std::get<0>(std::get<1>(p).second);

  std::cout << "Values: " << std::endl;
  PrintCollection(values);

  auto weights = std::get<1>(std::get<1>(p).second);

  std::cout << "Weights: " << std::endl;
  PrintCollection(weights);

  auto w = std::get<2>(std::get<1>(p).second);

  std::cout << "Capacity: " << w << std::endl;

  auto expected = std::get<3>(std::get<1>(p).second);
  auto actual = f(weights, values, w);

  EXPECT_EQ(actual, expected);
}