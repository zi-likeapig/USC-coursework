#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

std::vector<int> Reverse(std::vector<int> input) {
    int len=input.size();
    std::vector<int> output(len);
    for(int i=0;i<len;i++) 
        output[i]=input[len-i-1];
    return output;
}

std::vector<int> PlusOne(std::vector<int> input) {
    if(input.empty()) 
        return {};

    int number=0;
    for(int i=0;i<(int)input.size();i++) {
        if(input[i]>9 || input[i]<0) 
            return {-1};
        number=number*10+input[i];
    }
    number+=1;
    //std::cout<<number<<std::endl;

    std::vector<int> output;
    while(number!=0) {
        output.push_back(number%10);
        number/=10;
    }
    output=Reverse(output);
    return output;
}