#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(ProductOfKHighestNumbers, test1) {
    std::vector<int> input = {1, 10, 5, 4, 8, 9};
    std::vector<int> expect = {50, 200, 400, 720};
    EXPECT_EQ(ProductOfKHighestNumbers(input,3),expect);
}

TEST(ProductOfKHighestNumbers, smallsize) {
    std::vector<int> input = {1, 10, 5, 4, 8, 9};
    std::vector<int> expect = {};
    EXPECT_EQ(ProductOfKHighestNumbers(input,7),expect);
}

TEST(ProductOfKHighestNumbers, have_zero) {
    std::vector<int> input = {0, 10, 5, 4, 8, 9};
    std::vector<int> expect = {0, 50, 50, 80, 90};
    EXPECT_EQ(ProductOfKHighestNumbers(input,2),expect);
}

TEST(ProductOfKHighestNumbers, negative) {
    std::vector<int> input = {0, -10, 5, -4, 8, -9};
    std::vector<int> expect = {0, 0, 0, 40, 40};
    EXPECT_EQ(ProductOfKHighestNumbers(input,2),expect);
}