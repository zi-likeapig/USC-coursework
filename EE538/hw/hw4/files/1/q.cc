#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// On an m x n grid, where m is the number of rows and n is the number of
// columns. We want to know how many unique paths exists from start point to the
// end point. We can only move to the right or to the bottom direction. If a
// grid entry has 1, it means we can move to that location, otherwise, not.
//
// Example:
// Input grid: {1, 1, 1}, start = (0,0), end = (0, 2).
// Output: 1

// Input grid: {1, 0, 1}, start = (0,0), end = (0, 2).
// Output: 0

// Input grid: {
// {1, 1, 1},
// {1, 1, 1}
// }
// start = (0,0), end = (1, 2).
// Output: 3

// Input grid: {
// {1, 1, 1},
// {1, 0, 1}
// }
// start = (0,0), end = (1, 2).
// Output: 1


// Hint: At each location in the graph we have two choices. Try to use this to
// write a recursive relationship.
int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid, const std::pair<int, int> start, const std::pair<int, int> end) {
    if(grid.empty()) return 0;
    if(start.first<0 || start.first>=grid.size() || start.second<0 || start.second>=grid[0].size()) return 0;
    if(end.first<0 || end.first>=grid.size() || end.second<0 || end.second>=grid[0].size()) return 0;
    if(start.first>end.first || start.second>end.second) return 0;
    if(!grid[end.first][end.second]) return 0;
    if(end==start) return 1;

    int cnt_s=0;
    int cnt_h=0;
    if(end.first>start.first && grid[end.first-1][end.second]) {
        cnt_s=FindNumberOfUniquePaths(grid,start,{end.first-1,end.second});
    }
    if(end.second>start.second && grid[end.first][end.second-1]) {
        cnt_h=FindNumberOfUniquePaths(grid,start,{end.first,end.second-1});
    }

    return cnt_s+cnt_h;
}