#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void helper(std::vector<int> &tasks, int limit, int i, std::vector<int>& curr, std::vector<std::vector<int>>& rst) {
    if(limit==0) {
        rst.push_back(curr);
        return;
    }

    for(int idx=i;idx<tasks.size();idx++) {
        if(limit>=tasks[idx]) {
            curr.push_back(tasks[idx]);
            helper(tasks, limit-tasks[idx], idx, curr, rst);
            curr.pop_back();
        }
    }
    return;
}


std::vector<std::vector<int>> findResource(std::vector<int> &tasks, int limit) {
    if(limit<=0) return {};
    std::vector<std::vector<int>> rst={};
    std::vector<int> curr;
    helper(tasks, limit, 0, curr, rst);
    return rst;
}