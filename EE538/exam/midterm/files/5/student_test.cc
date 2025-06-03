#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------


TEST(MySetTest, DefaultConstructor) {
    MySet set;
    EXPECT_EQ(set.size(), 0);
}

TEST(MySetTest, ConstructorWithElements) {
    std::vector<int> elements = {5, 3, 8, 1, 3, 5};
    MySet set(elements);
    std::vector<int> expected = {1, 3, 5, 8};
    EXPECT_EQ(set.ConvertToStdVector(), expected);
}

TEST(MySetTest, CopyConstructor) {
    std::vector<int> elements = {1, 3, 5, 7};
    MySet originalSet(elements);
    MySet copiedSet = originalSet;
    EXPECT_EQ(copiedSet.ConvertToStdVector(), originalSet.ConvertToStdVector());
}

TEST(MySetTest, Insert) {
    MySet set;
    set.insert(10);
    set.insert(5);
    set.insert(20);
    set.insert(10);

    std::vector<int> expected = {5, 10, 20};
    EXPECT_EQ(set.ConvertToStdVector(), expected);
}

TEST(MySetTest, IsIn) {
    MySet set;
    set.insert(10);
    set.insert(20);

    EXPECT_TRUE(set.is_in(10));
    EXPECT_TRUE(set.is_in(20));
    EXPECT_FALSE(set.is_in(15));
}

TEST(MySetTest, Size) {
    MySet set;
    EXPECT_EQ(set.size(), 0);

    set.insert(10);
    set.insert(20);
    set.insert(10);

    EXPECT_EQ(set.size(), 2);
}

TEST(MySetTest, ConvertToStdVector) {
    MySet set;
    set.insert(30);
    set.insert(10);
    set.insert(20);

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(set.ConvertToStdVector(), expected);
}

TEST(MySetTest, FindInsertionIndex) {
    std::vector<int> sortedVector = {1, 3, 5, 7};
    EXPECT_EQ(findInsertionIndex(sortedVector, 0), 0); 
    EXPECT_EQ(findInsertionIndex(sortedVector, 2), 1); 
    EXPECT_EQ(findInsertionIndex(sortedVector, 5), 2); 
    EXPECT_EQ(findInsertionIndex(sortedVector, 8), 4);
}