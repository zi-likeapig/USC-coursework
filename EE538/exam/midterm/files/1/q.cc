#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Function to evaluate expressions consisting of decimal 0s and 1s, with '+'
// and '-' operators. Spaces in the expression are ignored. The '+' or '-' can
// be the first character in the expression. The function assumes the input is
// always valid. Returns the result of the expression as an integer.
// Example: input: 1+1+1-1, output : 2
// Example: input: -1+1, output : 0
int evaluateExpression(const std::string &expr) {
    int cur_number=0;
    int rst=0;
    bool ope=true; // default operator is '+' (when first character is not operator)
    for(auto c : expr) {
        if(c==' ') continue;    //ignore spaces
        else if(c=='+') {
            //check the previous operator
            rst= ope ? rst+cur_number : rst-cur_number; //if ope=1 -> +; if ope=0 -> -
            cur_number=0;
            //set the new operator
            ope=true;
        }
        else if(c=='-') {
            rst= ope ? rst+cur_number : rst-cur_number;
            cur_number=0;
            ope=false;
        }
        else {  //number
            cur_number=cur_number*10+(c-'0');
        }
    }

    // deal with the last number
    rst= ope ? rst+cur_number : rst-cur_number;

    return rst;
}