#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void helper(const std::vector<int> &students, std::vector<bool>& sit, 
            std::vector<int>& curr, std::vector<std::vector<int>>& rst) {
    if(curr.size()==students.size()) {
        rst.push_back(curr);
        return;
    }

    for(int i=0;i<students.size();i++) {
        if(curr.size()==0) {
            curr.push_back(students[i]);
            sit[i]=true;
            helper(students, sit, curr, rst);
            sit[i]=false;
            curr.pop_back();
            while(i<students.size()-1 && students[i]==students[i+1]) {
                i++;
            }
        }
        else {
            if(sit[i]==false && students[i]!=curr.back()) {
                curr.push_back(students[i]);
                sit[i]=true;
                helper(students, sit, curr, rst);
                sit[i]=false;
                curr.pop_back();
                while(i<students.size()-1 && students[i]==students[i+1]) {
                    i++;
                }
            }
        }
    }
    return;
}


std::vector<std::vector<int>> MovieTheaterAssignment(const std::vector<int> &students) {
    std::vector<std::vector<int>> rst;
    std::vector<int> curr;
    std::vector<bool> sit(students.size(),false);
    helper(students, sit, curr, rst);
    return rst;
}