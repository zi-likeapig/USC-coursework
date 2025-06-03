#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Default constructor initializes the calculator
Calculator::Calculator(){}

// Copy constructor creates a copy of another calculator instance
Calculator::Calculator(const Calculator &other):error_code(other.error_code),history(other.history) {}

// Performs a calculation given two integers and an operation
// Sets error_code to kDivisionByZero and returns 0 if a division by zero occurs
float Calculator::Calculate(int a, int b, Operation operation) {
    error_code=ErrorCode::kNoError; // reset default error code

    CalculationRecord newRecord;    //creat new record
    newRecord.op1=a;
    newRecord.op2=b;
    newRecord.operation=operation;

    switch(operation) {
        case Operation::kAdd:
            newRecord.result=float(a)+float(b);
            break;
        case Operation::kSubtract:
            newRecord.result=float(a)-float(b);
            break;
        case Operation::kMultiplication:
            newRecord.result=float(a)*float(b);
            break;
        case Operation::kDivision:
            if(b==0) {
                error_code=ErrorCode::kDivisionByZero;
                newRecord.result=0;
            }
            else newRecord.result=float(a)/float(b);
            break;
    }

    history.push_back(newRecord);

    return newRecord.result;
}

// Overloaded Calculate method that uses the result of the last calculation
// If there is no previous result, the first operand defaults to 0
float Calculator::Calculate(int a, Operation operation) {
    float pre_rst=0;    //defalte
    if(!history.empty()) pre_rst=history.back().result;

    return Calculate(a,pre_rst,operation);
}

// Retrieves a specific calculation record from the history
// Sets error_code to kInvalidIndex if the provided index is out of range 
// and returns a record where the operation is kAdd with other values being zeros.
// History(0) returns the most recent calculation record.
// History(1) returns one before the most recent calculation record.
CalculationRecord Calculator::History(int index) {
    error_code=ErrorCode::kNoError; // reset default error code
    if(index>=int(history.size())) {
        error_code=ErrorCode::kInvalidIndex;
        CalculationRecord errorRecord{0,0,Operation::kAdd,0}; //should it be pushed into history??
        return errorRecord;
    }
    return history[history.size()-1-index]; //inverse
}
