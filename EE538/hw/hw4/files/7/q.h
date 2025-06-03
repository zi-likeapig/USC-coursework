#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/**
 * This function is used by Google Test. Don't touch!
 */
template <class T>
void PrintCollection(std::string_view name, T input, bool add_new_line = true) {
  if (!name.empty()) {
    std::cout << name << ": ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size())
      std::cout << ", ";
  }
  std::cout << " }";
  if (add_new_line) {
    std::cout << std::endl;
  }
}

template <class T>
void Print2dVector(std::string_view name, std::vector<std::vector<T>> input) {
  std::cout << name << ": {" << std::endl;
  for (size_t i = 0; i < input.size(); i++) {
    std::cout << "  {";
    for (size_t j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "}" << std::endl;
}

//-----------------------------------------------------------------------------
// TODO:
/*
  Implement DFS without recursion.
*/

// Iterative DFS function to traverse the graph starting from vertex 's'.
// Returns the nodes that it visits.
std::vector<int> DFS(int s, std::map<int, std::vector<int>> &adjList);
