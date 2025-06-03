#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void UniqueVectorNotBySet(std::vector<int> &input) {
    for(int i=0;i<input.size();i++) {
        for(int j=i-1;j>=0;j--) {
            if(input[i]==input[j]) {
                input.erase(input.begin()+i);
                i--;
                break;
            }
        }
    }
}

void UniqueVectorBySet(std::vector<int> &input) {
    std::set<int> s;
    for(int i=0;i<input.size();i++) {
        if(s.count(input[i])) {
            input.erase(input.begin()+i);
            i--;
        }
        else s.insert(input[i]);
    }
}

/*
void UniqueVectorBySet(std::vector<int> &input) {
    std::set<int> s;
    int last_position=-1;
    for(int i=0;i<input.size();i++) {
        if(s.count(input[i])) {

        }
        else {
            input[last_position++]=input[i];
            s.insert(input[i]);
        }
    }

}
*/

std::vector<int> IntersectVectors(const std::vector<int> &input1, const std::vector<int> &input2) {
    std::set<int> s1,s2;
    std::vector<int> intersect;
    for(auto n:input1) 
        s1.insert(n);
    for(auto n:input2) 
        s2.insert(n);
    for(auto n:s1) {
        if(s2.count(n))
            intersect.push_back(n);
    }
    return intersect;
}

std::set<int> DiffVectors(const std::vector<int> &input1, const std::vector<int> &input2) {
    std::vector<int> intersect=IntersectVectors(input1,input2);
    std::set<int> s1;
    for(auto n:input1) 
        s1.insert(n);
    for(auto n:intersect) {
        if(s1.count(n)) 
            s1.erase(n);
    }
    return s1;
}