#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void SwapByPointer(float *input1, float *input2) {
    if(input1==nullptr || input2==nullptr) return;
    float a=(*input1);
    (*input1)=(*input2);
    (*input2)=a;
}

void SwapByReference(float &input1, float &input2) {
    float a=input1;
    input1=input2;
    input2=a;
}