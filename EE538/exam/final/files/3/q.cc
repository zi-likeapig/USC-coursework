#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int helper(std::vector<std::vector<char>> &grid, char c, std::pair<int,int> start, std::pair<int,int> target) {
    int row=grid.size(), col=grid[0].size();
    std::queue<std::pair<int,int>> q;
    q.push(start);
    int time=0;
    while(!q.empty()) {
        int size=q.size();
        time++;
        while(size>0) {
            std::pair<int,int> curr=q.front();  q.pop();
            int i=curr.first, j=curr.second;
            if(i>0 && (grid[i-1][j]=='0' || grid[i-1][j]=='t')) {
                if(grid[i-1][j]=='t') return time;
                grid[i-1][j]=time;
                q.push({i-1,j});
            }
            if(i<row-1 && (grid[i+1][j]=='0' || grid[i+1][j]=='t')) {
                if(grid[i+1][j]=='t') return time;
                grid[i+1][j]=time;
                q.push({i+1,j});
            }
            if(j>0 && (grid[i][j-1]=='0' || grid[i][j-1]=='t')) {
                if(grid[i][j-1]=='t') return time;
                grid[i][j-1]=time;
                q.push({i,j-1});
            }
            if(j<col-1 && (grid[i][j+1]=='0' || grid[i][j+1]=='t')) {
                if(grid[i][j+1]=='t') return time;
                grid[i][j+1]=time;
                q.push({i,j+1});
            }

            size--;
        }
    }
    return -1;
}


int fastestToTarget(std::vector<std::vector<char>> &grid) {
    std::vector<std::vector<char>> gridf=grid;
    std::pair<int,int> y, f, t;
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(grid[i][j]=='y') {
                y.first=i;  y.second=j;
                gridf[i][j]='0';
            }
            else if(grid[i][j]=='f') {
                f.first=i;  f.second=j;
                grid[i][j]='0';
            }
            else if(grid[i][j]=='t') {
                t.first=i;  t.second=j;
            }
        }
    }
    int yt=helper(grid, 'y', y, t);
    int ft=helper(gridf, 'f', f, t);
    //std::cout<<yt<<" vs "<<ft<<"\n";

    if(yt==-1 && ft==-1) return -1;

    if(yt<ft && yt!=-1) return 1;
    else if(yt>ft && ft!=-1) return 2;
    else if(yt==ft) return 3;
}