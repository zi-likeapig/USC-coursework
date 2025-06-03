#ifndef SOL_4_Q
#define SOL_4_Q
#include <iostream>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------
// Given a sorted vector (in an ascending order) of integers with no duplicates
// and an integer n, find at what index n should be inserted such that the
// result is sorted. If the vector is empty, insert should be at index 0. If n
// exists, just return the index of n.

// Example:
// in: sortedVector= {}, n = 1
// out: 0.
// in: sortedVector= {1}, n = 1
// out: 0.
// in: sortedVector= {1, 7}, n = 2
// out: 1.
int findInsertionIndex(const std::vector<int>& sortedVector, int n);

//-----------------------------------------------------------------------------
// Implement your own set class!
// Use a sorted vector internally to store the elements.
//
// TODO: Implement these functions in q.cc.
// Write the runtime complexity of each function in the README file.
// You can only use std::sort. No other std:: functions are allowed.
class MySet {
 public:
  // Creates an empty set. Already implemented as an inline function.
  // No need to change this.
  MySet() {}

  // TODO: Implement the following function.
  // Creates a set from the given elements.
  MySet(std::vector<int>& elements);

  // Copy constructor.
  MySet(const MySet& rhs);

  // Inserts the given value if it doesn't exist.
  // Use findInsertionIndex function.
  void insert(int value);

  // Returns true if item is in the set.
  bool is_in(int item);

  // Returns the size of the set.
  int size() const;

  // Converts to std::vector. It should return the values in a sorted ascending
  // order.
  std::vector<int> ConvertToStdVector();

 private:
  // Store the elements here. Keep this as a sorted vector.
  std::vector<int> elements_;
};

#endif /* SOL_4_Q */
