#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Function to compute the set difference (elements present in set1 but not in
// set2)
std::set<int> setDifference(const std::set<int> &set1, const std::set<int> &set2) {
    std::set<int> diff;
    for(auto n:set1) {
        if(!set2.count(n))
            diff.insert(n);
    }
    return diff;
}

// Function to check if two sets are disjoint (have no common elements)
bool areDisjoint(const std::set<int> &set1, const std::set<int> &set2) {
    for(auto n:set1) {
        if(set2.count(n)) return false;
    }
    return true;
}