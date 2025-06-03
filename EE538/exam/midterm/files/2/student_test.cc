#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(LinkedList, test) {
    LinkedList list;

    // {} empty return -1
    EXPECT_EQ(list.front(), -1);
    EXPECT_EQ(list.back(), -1);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    // {10,20,30}
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 30);

    list.pop_back();
    // {10,20}
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);

    list.pop_back();
    // {10}
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 10);

    list.pop_back();
    // {} empty return -1
    EXPECT_EQ(list.front(), -1);
    EXPECT_EQ(list.back(), -1);

    list.pop_back();  // Should not crash
    EXPECT_EQ(list.front(), -1);
    EXPECT_EQ(list.back(), -1);
}