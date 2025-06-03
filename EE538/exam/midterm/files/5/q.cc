#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Creates a set from the given elements.
MySet::MySet(std::vector<int>& elements) {
    elements_.clear();

    if(elements.empty()) return;    //empty

    /*elements_.push_back(elements[0]);
    for(int i=1;i<elements.size();i++) {
        int position=0;
        for(int position=0;position<elements_.size();position++) {
            if(elements[i]>elements_[position]) continue;  //for order
            else if(elements[i]==elements_[position]) break;    //exist
            else if(elements[i]<elements_[position]) { //find position
                elements_.insert(elements_.begin()+position,elements[i]);
                break;
            }
        }
        if(position==elements_.size()) elements_.push_back(elements[i]);
    }*/
    for(auto& e : elements) {
        insert(e);
    }
}

// Copy constructor.
MySet::MySet(const MySet& rhs) {
    elements_.clear();
    for(auto& e : rhs.elements_) {
        elements_.push_back(e);
    }
}

// Inserts the given value if it doesn't exist.
// Use findInsertionIndex function.
void MySet::insert(int value) {
    int position=findInsertionIndex(elements_,value);
    if(position<elements_.size() && elements_[position]==value) return;  //exist
    elements_.insert(elements_.begin()+position,value);
}

// Returns true if item is in the set.
bool MySet::is_in(int item) {
    for(auto& e : elements_) {
        if(e==item) return true;    //exist
    }
    return false;   //not find
}

// Returns the size of the set.
int MySet::size() const { return elements_.size(); }

// Converts to std::vector. It should return the values in a sorted ascending
// order.
std::vector<int> MySet::ConvertToStdVector() { return elements_; }


int findInsertionIndex(const std::vector<int>& sortedVector, int n) {
    int position=0;
    for(;position<sortedVector.size();position++) {
        if(n>sortedVector[position]) continue;  
        else if(n==sortedVector[position]) return position;    //exist
        else if(n<sortedVector[position]) return position;  //find position
    }
    return position;    // the biggest, insert back
}