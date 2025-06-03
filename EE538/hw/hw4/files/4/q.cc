#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// TODO: Implement the following class:
// A Max Heap that contains objects of type Student.
// We compare the students only based on their grade, not their names. That
// means the student with the highest grade should always be at the top of the
// heap.

   
// Returns the parent of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetParent(int i) {
    int parent_idx=GetParentIndex(i);
    if(parent_idx==INT_MAX) return Student("NO_NAME", INT_MIN);
    else return data_[parent_idx];
}
   
// Returns the left child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetLeft(int i) {
    int left_idx=GetLeftIndex(i);
    if(left_idx==INT_MAX) return Student("NO_NAME", INT_MIN);
    else return data_[left_idx];
}
   
// Returns the right child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetRight(int i) {
    int right_idx=GetRightIndex(i);
    if(right_idx==INT_MAX) return Student("NO_NAME", INT_MIN);
    else return data_[right_idx];
}
   
// Returns the index of the parent of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetParentIndex(int i) {
    if(i==0) return INT_MAX;
    else return (i-1)/2;
}
   
// Returns the index of the left child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLeftIndex(int i) {
    int left_idx=i*2+1;
    if(left_idx>=size()) return INT_MAX;
    else return left_idx;
}
   
// Returns the index of the right child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetRightIndex(int i) {
    int right_idx=i*2+2;
    if(right_idx>=size()) return INT_MAX;
    else return right_idx;
}
   
// Returns the index of the largest child of a node given its index in the
// tree. Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLargestChildIndex(int i) {
    Student left=GetLeft(i);
    Student right=GetRight(i);
    //cout<<i<<":"<<left.grade<<"--"<<right.grade<<endl;

    if(left.grade==INT_MIN && right.grade==INT_MIN) return INT_MAX;

    return (left>right) ? GetLeftIndex(i) : GetRightIndex(i);
}
   
// Returns the top of the heap. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::top() {
    if(size()==0) return Student("NO_NAME", INT_MIN);
    else return data_[0];
}
   
// Performs trickle up. It should use the overloaded operators of the Student class.
void StudentMaxHeap::TrickleUp(int i) {
    while(i!=0 && data_[i]>GetParent(i)) {
        Student swap=data_[i];
        data_[i]=data_[GetParentIndex(i)];
        data_[GetParentIndex(i)]=swap;

        i=GetParentIndex(i);
    }
}
   
// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleDown(int i) {
    //cout<<"max_child_idx of "<<i<<"="<<GetLargestChildIndex(i)<<endl;
    while(GetLargestChildIndex(i)!=INT_MAX) {
        int max_child_idx=GetLargestChildIndex(i);

        if(data_[i]>data_[max_child_idx]) return;

        Student swap=data_[i];
        data_[i]=data_[max_child_idx];
        data_[max_child_idx]=swap;

        i=max_child_idx;
    }
}
   
// Adds a new Student to the heap.
void StudentMaxHeap::push(const Student& student) {
    data_.push_back(student);
    TrickleUp(data_.size()-1);
}
   
// Removes the top. Returns
// true if successful and false otherwise.
bool StudentMaxHeap::pop() {
    if(empty()) return false;

    //cout<<"when pop "<<data_[0].grade<<endl;
    data_[0]=data_[data_.size()-1];
    data_.pop_back();
    TrickleDown(0);
    return true;
}

// Converts the given input into a max heap and stores that into data_.
void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input) {
    data_=input;
    for(int i=(size()-1)/2;i>=0;i--) {
        TrickleDown(i);
    }
}

// Parameterized constructor: creates a max heap from the given input.
StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input) {
    ConvertToHeap(input);
}

//-----------------------------------------------------------------------------
// TODO: Implement this function:
// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades. Use heap sort!
void HeapSort(std::vector<Student>& input) {
    StudentMaxHeap maxheap(input);
    for(int i=input.size()-1;i>=0;i--) {
        /*std::vector<Student> data=maxheap.GetData();
        cout<<"befor erase:"<<endl;
        for(int j=0;j<maxheap.size();j++) {
            cout<<data[j].grade<<endl;
        }*/
        input[i]=maxheap.top();
        maxheap.pop();
    }
}