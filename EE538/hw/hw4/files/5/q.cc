#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/**
Given a map, represented by a matrix of values 0 and 1,
a hiker must find a path from index [0][0] to [n-1][m-1].

The hiker can only travel to right, down, left, up.

It can only travel on 0 values. 1 values represent obstacles.

Return a path that takes the hiker from [0][0] to [n-1][m-1].

If there are multiple paths, you should return the path in which
when there is a choice, the precedence should be as follows:

1. Right (Highest precedence)
2. down
3. left
4. up (lowest precedence)

Return [-1,-1] if there is no path.

Example:

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


*/
void print(std::vector<std::vector<int>> path) {
    std::cout<<"{";
    for(auto& node:path) {
        std::cout<<"{"<<node[0]<<","<<node[1]<<"}, ";
    }
    std::cout<<"}"<<std::endl;
}

bool DFShelper(std::vector<int>& start, std::vector<std::vector<int>>& path, 
               const std::vector<std::vector<int>>& maze, const int& n, const int& m,
               std::vector<std::vector<bool>>& visited) {
    path.push_back(start);
    
    int row=start[0];
    int col=start[1];
    //std::cout<<"("<<row<<","<<col<<")"<<std::endl;
    //print(path);
    
    if(row==n-1 && col==m-1) return true;

    visited[row][col]=true;

    //right
    if(col<m-1 && maze[row][col+1]==0 && !visited[row][col+1]) {
        std::vector<int> next={row,col+1};
        if(DFShelper(next, path, maze, n, m, visited)) return true;
    }
    //down
    if(row<n-1 && maze[row+1][col]==0 && !visited[row+1][col]) {
        std::vector<int> next={row+1,col};
        if(DFShelper(next, path, maze, n, m, visited)) return true;
    }
    //left
    if(col>0 && maze[row][col-1]==0 && !visited[row][col-1]) {
        std::vector<int> next={row,col-1};
        if(DFShelper(next, path, maze, n, m, visited)) return true;
    }
    //up
    if(row>0 && maze[row-1][col]==0 && !visited[row-1][col]) {
        std::vector<int> next={row-1,col};
        if(DFShelper(next, path, maze, n, m, visited)) return true;
    }

    //std::cout<<"pop?"<<std::endl;
    path.pop_back();
    return false;
}

std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze) {
    if(maze.empty()) return {{-1,-1}};

    int n=maze.size();
    int m=maze[0].size();

    if(maze[0][0]==1 || maze[n-1][m-1]==1) return {{-1,-1}};

    std::vector<int> start={0,0};
    std::vector<std::vector<int>> path;
    std::vector<std::vector<bool>> visited(n,std::vector<bool>(m,false));

    if(DFShelper(start, path, maze, n, m, visited)) return path;
    else return {{-1,-1}};
}

