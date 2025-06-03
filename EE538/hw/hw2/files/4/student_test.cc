#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(UniqueVectorTest, Empty) {
    std::vector<int> v1, v2;
    v1 = v2 = { };
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = { };
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}

TEST(UniqueVectorTest, OneElement) {
    std::vector<int> v1, v2;
    v1 = v2 = {-1};
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = {-1};
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}

TEST(UniqueVectorTest, unique) {
    std::vector<int> v1, v2;
    v1 = v2 = {1, 2, 3, 4, 5, 6};
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}

TEST(UniqueVectorTest, Ordered1) {
    std::vector<int> v1, v2;
    v1 = v2 = {1, 2, 2, 4, 4, 5};
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = {1, 2, 4, 5};
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}

TEST(UniqueVectorTest, Ordered2) {
    std::vector<int> v1, v2;
    v1 = v2 = {2, 2, 2, 2, 2, 2};
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = {2};
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}

TEST(UniqueVectorTest, UnOrdered) {
    std::vector<int> v1, v2;
    v1 = v2 = {2, 4, 1, 2, 6, 6, 8, -1, 2};
    UniqueVectorNotBySet(v1);
    UniqueVectorBySet(v2);
    std::vector<int> expected = {2, 4, 1, 6, 8, -1};
    EXPECT_EQ(v1, expected);
    EXPECT_EQ(v2, expected);
}


/*---------------------------------------------------------------------------*/

TEST(VectorOperationsTest, Empty1) {
    std::vector<int> v1 = { };
    std::vector<int> v2 = { };

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = { };
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = { };
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Empty2) {
    std::vector<int> v1 = { };
    std::vector<int> v2 = {1, 2, 3, 4};

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = { };
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = { };
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Empty3) {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = { };

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = { };
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = {1, 2, 3, 4};
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Belong1) {
    std::vector<int> v1 = {2, 3, 5, 6, 1};
    std::vector<int> v2 = {1, 2, 3};

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = {1, 2, 3};
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = {5, 6};
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Belong2) {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {2, 3, 5, 6, 1};

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = {1, 2, 3};
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = { };
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Test1) {
    std::vector<int> v1 = {1, 2, 2, 3};
    std::vector<int> v2 = {3, 4, 4, 5};

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = {3};
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = {1, 2};
    EXPECT_EQ(diff, diff_expected);
}

TEST(VectorOperationsTest, Test2) {
    std::vector<int> v1 = {1, 2, 2};
    std::vector<int> v2 = {4, 4, 5};

    std::vector<int> intersect = IntersectVectors(v1, v2);
    std::vector<int> intersect_expected = { };
    EXPECT_EQ(intersect, intersect_expected);

    std::set<int> diff = DiffVectors(v1, v2);
    std::set<int> diff_expected = {1, 2};
    EXPECT_EQ(diff, diff_expected);
}
