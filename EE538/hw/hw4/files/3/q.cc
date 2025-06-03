#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/**
 * Given a vector of integers, we want to produce the product of the current 
 * highest k > 0 of these numbers. If the input vector size is less than k,
 * then the output should be empty. The size of the output vector is equal to
 *  `input.size() - k + 1`.
 *
 * Example:
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 3
 * Output: {50, 200, 400, 720}
 * explanation: 
 * 
 * 1 * 10 * 5 = 50, (1, 10, 5 are the largest ones in {1, 10, 5})
 * 10 * 5 * 4 = 200, (10, 5, 4 are the largest ones in {1, 10, 5, 4})
 * 10 * 5 * 8 = 400, (10, 5, 8 are the largest ones in {1, 10, 5, 4, 8})
 * 10 * 8 * 9 = 720 (10, 8, 9 are the largest ones in {1, 10, 5, 4, 8, 9})
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 13
 * Output: {}
 */

 std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k) {
    if(input.size()<k) return {};

    std::vector<int> ans;
    std::multiset<int> s;
    int produce=1;
    bool have_zero=false;
    for(int i=0;i<k;i++) {
        if(input[i]==0) have_zero=true;
        produce*=input[i];
        s.insert(input[i]);
    }
    ans.push_back(produce);
    for(int i=k;i<input.size();i++) {
        if(input[i]>*(s.begin())) {
            int small=*(s.begin());
            if(small!=0) produce/=small;
            s.erase(s.begin());

            if(have_zero && !s.count(0)) {  //no zero
                have_zero=false;
                produce=1;
                for(auto& n:s) {
                    produce*=n;
                }
            }

            produce*=input[i];
            s.insert(input[i]);
        }
        ans.push_back(produce);
    }
    return ans;
}