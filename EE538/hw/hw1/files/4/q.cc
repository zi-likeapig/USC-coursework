#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

std::vector<int> Flatten3DVector(std::vector<std::vector<std::vector<int>>> input) {
    std::vector<int> output;
    for(int i=0;i<input.size();i++) {
        for(int j=0;j<input[i].size();j++) {
            for(int t=0;t<input[i][j].size();t++) {
                output.push_back(input[i][j][t]);
            }
        }
    }
    return output;
}