#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Function to add an element to the back of the array. Updates both array and
// size.
void push_back(int *&array, int &size, int element) {
    int *new_array=new int[++size];
    int i=0;
    for(;i<size-1;i++) 
        new_array[i]=array[i];
    new_array[i]=element;
    delete[] array;
    array=new_array;
}

// Function to remove the last element from the array. Updates both array and
// size.
// No operations if array is empty.
void pop_back(int *&array, int &size) {
    if(size==0) return;
    int *new_array=new int[--size];
    for(int i=0;i<size;i++) 
        new_array[i]=array[i];
    delete[] array;
    array=new_array;
}

// Function to insert an element at a specific index in the array. Updates both
// array and size.
void insert(int *&array, int &size, int element, int index) {
    if(index<0 || index>size) return;
    int *new_array=new int[++size];
    for(int i=0;i<size-1;i++) {
        if(i==index){
            new_array[i]=element;
            new_array[i+1]=array[i];
        }
        else if (i>index)
            new_array[i+1]=array[i];
        else new_array[i]=array[i];
    }
    if(index==size-1) 
        new_array[index]=element;
    delete[] array;
    array=new_array;
    /*for(int i=0;i<size;i++){
        std::cout<<array[i]<<std::endl;
    }
    std::cout<<std::endl;*/
}

// Function to erase an element at a specific index from the array.
// Returns -1 for errors (index out of bound) and 0 otherwise. Updates both
// array and size.
int erase(int *&array, int &size, int index) {
    if(size==0 || index>=size || index<0) return -1;
    int *new_array=new int[--size];
    for(int i=0;i<size+1;i++)  {
        if(i==index)
            continue;
        else if (i>index)
            new_array[i-1]=array[i];
        else new_array[i]=array[i];
    }
    delete[] array;
    array=new_array;
    return 0;
}

// Function to find the first occurrence of an element in the array.
// Return -1 if it didn't exist.
int find(const int *array, int size, int element) {
    for(int i=0;i<size;i++) {
        if (array[i]==element)
            return i;
    }
    return -1;
}
