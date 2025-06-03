#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/*
  Implement DFS without recursion.
*/

// Iterative DFS function to traverse the graph starting from vertex 's'.
// Returns the nodes that it visits.
std::vector<int> DFS(int s, std::map<int, std::vector<int>> &adjList) {
    if(adjList.empty()) return {};
    
    std::unordered_set<int> marked;
    marked.insert(s);

    std::vector<int> visited;
    visited.push_back(s);

    std::stack<int> sk;
    sk.push(s);

    while(!sk.empty()) {
        int now=sk.top();
        sk.pop();
        for(auto& neighbor:adjList[now]) {
            if(!marked.count(neighbor)) {
                marked.insert(neighbor);
                visited.push_back(neighbor);
                sk.push(neighbor);
            }
        }
    }

    return visited;
}