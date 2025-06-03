#include <set>
#include <vector>
// Write a function that takes a vector of positive integers as input. The
// output is the same vector where all duplicates are removed. Note that the
// output is the same vector means the function's return type should be void
// and do the modifications on the input vector.
//
// Example: before: v=[1, 2, 2, 4],
//
// after : v=[1, 2, 4]
//

// Solve this for the following cases:
//
// You cannot use std::set and std::map.
void UniqueVectorNotBySet(std::vector<int> &input);
//
// You can use std::set, but you cannot use std::map.
void UniqueVectorBySet(std::vector<int> &input);

// Write a function that takes two vectors v1 and v2 and returns a new vector
// that is the intersection of the values in v1 and v2. All the values in
// return vector should be unique.
//
// Example: input: v1={1, 2, 2, 3}, v2={3, 4, 4, 5}, output = {3}
std::vector<int> IntersectVectors(const std::vector<int> &input1,
                                  const std::vector<int> &input2);

// Write a function that takes two vectors v1 and v2 and returns a new vector
// that is the difference v1 and v2, i.e. all unique values that are in v1, but
// not in v2.
// Your implementation should use `IntersectVectors` as a blackbox.
// You should not use any std:: function. However, using vector.find is ok.
//
// Example: input: v1={1, 2, 2, 3}, v2={3, 4, 4, 5}, output = {1, 2}
std::set<int> DiffVectors(const std::vector<int> &input1,
                          const std::vector<int> &input2);
