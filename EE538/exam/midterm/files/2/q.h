// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//-----------------------------------------------------------------------------
// TODO: Implement the member functions of these classes and structs in q.cc
// file. DO NOT MODIFY THIS FILE.
//-----------------------------------------------------------------------------
// Node structure for the singly linked list elements.
struct Node {
  int value;     // Value stored in the node
  Node *next;    // Pointer to the next node in the list
  Node(int val); // Constructor to initialize a node with a value
};

// Class for the singly linked list.
// Class for the singly linked list.
class LinkedList {
private:
  Node *head; // Pointer to the first node in the list
  Node *tail; // Pointer to the last node in the list

public:
  // Constructor to initialize an empty list
  LinkedList();

  // Destructor to free the allocated memory
  ~LinkedList();

  // Adds a value to the end of the list. Should be O(1).
  void push_back(int value);

  // Returns the value of the last element or -1 if the list is empty. Should be
  // O(1).
  int back();

  // Returns the value of the first element or -1 if the list is empty. Should
  // be O(1).
  int front();

  // Removes the last element from the list
  void pop_back();
};

#endif // LINKEDLIST_H
