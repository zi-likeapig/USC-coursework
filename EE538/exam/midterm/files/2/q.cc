#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Constructor to initialize a node with a value
Node::Node(int val):value(val),next(nullptr){}

// Constructor to initialize an empty list
LinkedList::LinkedList():head(nullptr),tail(nullptr) {}

// Destructor to free the allocated memory
LinkedList::~LinkedList() {
    while(head!=nullptr) pop_back();
}

// Adds a value to the end of the list. Should be O(1).
void LinkedList::push_back(int value) {
    Node* newNode=new Node(value);
    if(head==nullptr) {     //  empty
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

// Returns the value of the last element or -1 if the list is empty. Should be
// O(1).
int LinkedList::back() {
    if(tail==nullptr) return -1;
    else return tail->value;
}

// Returns the value of the first element or -1 if the list is empty. Should
// be O(1).
int LinkedList::front() {
    if(head==nullptr) return -1;
    else return head->value;
}

// Removes the last element from the list
void LinkedList::pop_back() {
    if(tail==nullptr) return;   // empty
    if(head==tail) {    // only one node
        delete head;
        head=nullptr;
        tail=nullptr;
        return;
    }
    Node* pre_tail=head;    //find the node in front of tail
    while(pre_tail->next!=tail) {
        pre_tail=pre_tail->next;
    }
    delete tail;
    tail=pre_tail;
    pre_tail->next=nullptr;
}