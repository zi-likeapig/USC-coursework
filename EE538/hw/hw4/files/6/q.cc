#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/*
Given a 2D grid of characters, find the number of connected components in the
grid. A connected component is a group of cells with value '1' that are all
connected to each other by horizontal or vertical lines.

Examples:

Input:
1 1 1 1
1 0 0 1
1 0 0 0
1 1 1 1
Output:
1

Input:
1 1 1 1
0 0 0 0
0 0 0 0
1 1 1 1
Output:
2

Input:
1 1 1 1
0 0 0 1
1 0 0 0
0 1 1 1
Output:
3

*/
int NumConnectedComponents(std::vector<std::vector<char>>& maze) {
    if(maze.empty()) return 0;

    int n=maze.size();
    int m=maze[0].size();

    std::vector<std::vector<bool>> visited(n,std::vector<bool>(m,false));

    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j] && maze[i][j]=='1') {
                //std::cout<<i<<"---"<<j<<std::endl;
                cnt++;

                visited[i][j]=true;

                std::queue<pair<int,int>> q;
                q.push(pair(i,j));
                while(!q.empty()) {
                    pair<int,int> now=q.front();
                    q.pop();

                    int row=now.first;
                    int col=now.second;

                    //right
                    if(col<m-1 && maze[row][col+1]=='1' && !visited[row][col+1]) {
                        q.push(pair(row,col+1));
                        visited[row][col+1]=true;
                    }
                    //down
                    if(row<n-1 && maze[row+1][col]=='1' && !visited[row+1][col]) {
                        q.push(pair(row+1,col));
                        visited[row+1][col]=true;
                    }
                    //left
                    if(col>0 && maze[row][col-1]=='1' && !visited[row][col-1]) {
                        q.push(pair(row,col-1));
                        visited[row][col-1]=true;
                    }
                    //up
                    if(row>0 && maze[row-1][col]=='1' && !visited[row-1][col]) {
                        q.push(pair(row-1,col));
                        visited[row-1][col]=true;
                    }
                }
            }
        }
    }
    return cnt;
}