#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


// Constructor
DoubleStack::DoubleStack() { }

// Pushes the number in evenVec_ if the input is even
// Pushes the number in oddVec_ if the input is odd
void DoubleStack::push(int num) {
    (num%2) ? oddVec_.push_back(num): evenVec_.push_back(num);
}

// Removes the maximum number from the top of both vectors.
// It does not do anything if both stacks are empty.
void DoubleStack::pop() {
    if(empty()) return;
    if(evenVec_.empty()) {
        oddVec_.pop_back();
        return;
    }
    else if(oddVec_.empty()) {
        evenVec_.pop_back();
        return;
    }

    (evenVec_.back()>oddVec_.back()) ? evenVec_.pop_back() : oddVec_.pop_back();
    
    return;
}

// Returns the maximum number from the top of both vectors.
// It returns -1 if both stacks are empty.
int DoubleStack::top() {
    if(empty()) return -1;
    else if(evenVec_.empty()) return oddVec_.back();
    else if(oddVec_.empty()) return evenVec_.back();

    return std::max(evenVec_.back(),oddVec_.back());
}

// Returns the size of evenVec_ plus the size of oddVec_
int DoubleStack::size() {
    return evenVec_.size()+oddVec_.size();
}

// Returns true if both vectors are empty, false otherwise
bool DoubleStack::empty() {
    return (oddVec_.empty()) && (evenVec_.empty());
}