#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


// Creates an empty vector.
MyVector::MyVector():data_(nullptr),size_(0),error_(ErrorCode::kNoError) { }

// Creates a vector of the given size with the value to be zero.
MyVector::MyVector(int size) {
    if(size<0) {
        data_=nullptr;
        size_=0;
        error_=ErrorCode::kIndexError;
    }
    else if(size==0) {
        data_=nullptr;
        size_=0;
        error_=ErrorCode::kNoError;
    }
    else {
        size_=size;
        data_=new int[size]{0}; // is 0 the true item?????
        error_=ErrorCode::kNoError;
    }
}

// Copy constructor.
MyVector::MyVector(const MyVector& rhs):size_(rhs.size_),error_(rhs.error_) {
    if(rhs.size_==0) {
        data_=nullptr;
    }
    else {
        data_=new int[size_];
        for(int i=0;i<size_;i++) {
            data_[i]=rhs.data_[i];
        }
    }
}

// Destructor.
MyVector::~MyVector() {
    error_=ErrorCode::kNoError;
    if(data_!= nullptr) {
        delete[] data_;
        data_ = nullptr;
    }
    size_=0;
}

// Inserts the given value at the back of the vector.
void MyVector::push_back(int value) {
    error_=ErrorCode::kNoError; // reset the error code
    int* new_data=new int[size_+1];
    for(int i=0;i<size_;i++) {  
        new_data[i]=data_[i];
    }
    new_data[size_]=value;  // new element
    if(data_!=nullptr) delete[] data_;
    data_=new_data;
    ++size_;
}

// Removes and returns a value from the backs of the vector.
int MyVector::pop_back() {
    error_=ErrorCode::kNoError; // reset the error code

    if(size_==0) {  //empty
        error_=ErrorCode::kPopFromEmptyVector;
        return -1;   // return what???
    }
    else if(size_==1) { //if only have 1 element, set data_=nullptr
        int back_value=data_[0];
        delete[] data_;
        data_=nullptr;
        size_=0;
        return back_value;
    }

    int back_value=data_[size_-1];
    int* new_data=new int[size_-1]; //new array
    --size_;
    for(int i=0;i<size_;i++) {  
        new_data[i]=data_[i];
    }
    delete[] data_;
    data_=new_data;
    return back_value;
}

// Inserts the given value at the front of the vector.
void MyVector::push_front(int value) {
    error_=ErrorCode::kNoError; // reset the error code
    int* new_data=new int[size_+1];
    new_data[0]=value;
    for(int i=0;i<size_;i++) {  
        new_data[i+1]=data_[i];
    }
    if(data_!=nullptr) delete[] data_;
    data_=new_data;
    ++size_;
}

// Removes and returns a value from the front of the vector.
int MyVector::pop_front() {
    error_=ErrorCode::kNoError; // reset the error code

    if(size_==0) {  //empty
        error_=ErrorCode::kPopFromEmptyVector;
        return -1;   // return what???
    }
    else if(size_==1) { //if only have 1 element, set data_=nullptr
        int first_value=data_[0];
        delete[] data_;
        data_=nullptr;
        size_=0;
        return first_value;
    }

    int first_value=data_[0];
    int* new_data=new int[size_-1]; //new array
    for(int i=1;i<size_;i++) {  
        new_data[i-1]=data_[i];
    }
    --size_;
    delete[] data_;
    data_=new_data;
    return first_value;
}

// Inserts the given value after the given index.
// 1. Create a new dynamic array
// 2. Copy from the old array until index
// 3. insert value
// 4. Copy the rest from the old array.
// 5. DELETE the array.
// 6. return the pointer inside the new dynamic array.

// If the given index is -1, it inserts the item at the very beginning of the
// vector.
// If the given index is invalid, set the error code.
void MyVector::insert(int value, int index) {
    error_=ErrorCode::kNoError; // reset the error code
    if(index<-1 || index>=size_) {
        error_=ErrorCode::kIndexError;
        return;
    }

    if(index==-1) {
        push_front(value);
        return;
    }

    /*int* new_data=new int[size_+1];
    ++size_;

    for(int i=0;i<size_;i++) {  
        if(i==index) new_data[i]=value;
        else if(i<index) new_data[i]=data_[i];
        else if(i>index) new_data[i]=data_[i-1];
    }
    delete[] data_;
    data_=new_data;*/
    int* new_data=new int[size_+1];

    for(int i=0;i<index+1;i++) {
        new_data[i]=data_[i];
    }
    
    new_data[index+1]=value;
    
    for(int i=index+1;i<size_;i++) {
        new_data[i+1]=data_[i];
    }
    
    if(data_!=nullptr) delete[] data_;
    data_=new_data;
    ++size_;
}

// Returns the item at the given index. Returns -1 if the index is not valid.
int MyVector::at(int index) {
    error_=ErrorCode::kNoError; // reset the error code

    if(size_==0 || index<0 || index>=size_) {   // invalid index
        error_=ErrorCode::kIndexError;
        return -1;
    }

    return data_[index];
}

// Returns the first index of the given item in the vector. Returns -1 if not
// found.
int MyVector::find(int item) {
    error_=ErrorCode::kNoError; // reset the error code

    for(int i=0;i<size_;i++) {
        if(data_[i]==item) {
            return i;
        }
    }
    error_=ErrorCode::kNotFound;
    return -1;
}

// Returns the value of error_
ErrorCode MyVector::get_error() const { return error_; }

// Returns the value of size_
int MyVector::size() const { return size_; }

// Converts to std::vector. Used for testing.
std::vector<int> MyVector::ConvertToStdVector() {
    error_=ErrorCode::kNoError;
    std::vector<int> v;
    if(data_==nullptr) return v;
    for(int i=0;i<size_;i++) {
        v.push_back(data_[i]);
    }
    return v;
}