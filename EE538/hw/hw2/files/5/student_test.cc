#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

bool compareArrays(int *arr, int *expected, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != expected[i]) {
            std::cout<<arr[i]<<"---------"<<expected[i]<<std::endl;
            return false;
        }
    }
    return true;
}

TEST(DynamicArrayTest, PushBack1) {
    int size = 3;
    int *arr = new int[size]{1, 2, 3};

    push_back(arr, size, 4);

    int expected[] = {1, 2, 3, 4};
    EXPECT_EQ(size, 4);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    delete[] arr;
}

TEST(DynamicArrayTest, PushBack2) {
    int size = 0;
    int *arr = new int[size]{ };

    push_back(arr, size, 4);

    int expected[] = {4};
    EXPECT_EQ(size, 1);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    delete[] arr;
}

TEST(DynamicArrayTest, PopBack1) {
    int size = 4;
    int *arr = new int[size]{1, 2, 3, 4};

    pop_back(arr, size);

    int expected[] = {1, 2, 3};
    EXPECT_EQ(size, 3);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    delete[] arr;
}

TEST(DynamicArrayTest, PopBack2) {
    int size = 0;
    int *arr = new int[size]{ };

    pop_back(arr, size);

    int expected[] = { };
    EXPECT_EQ(size, 0);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    delete[] arr;
}

TEST(DynamicArrayTest, Insert1) {
    int size = 3;
    int *arr = new int[size]{1, 2, 3};

    insert(arr, size, 99, 1);  // Insert 99 at index 1
    int expected1[] = {1, 99, 2, 3};
    EXPECT_EQ(size, 4);
    EXPECT_TRUE(compareArrays(arr, expected1, size));

    insert(arr, size, -1, 0);  // Insert -1 at index 0
    int expected2[] = {-1, 1, 99, 2, 3};
    EXPECT_EQ(size, 5);
    EXPECT_TRUE(compareArrays(arr, expected2, size));

    insert(arr, size, 0, 5);  // Insert 0 at index 5
    int expected3[] = {-1, 1, 99, 2, 3, 0};
    EXPECT_EQ(size, 6);
    EXPECT_TRUE(compareArrays(arr, expected3, size));

    delete[] arr;
}

TEST(DynamicArrayTest, Insert2) {
    int size = 3;
    int *arr = new int[size]{1, 2, 3};

    insert(arr, size, 99, -1);  // Insert 99 at index 1
    int expected[] = {1, 2, 3};
    EXPECT_EQ(size, 3);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    insert(arr, size, 99, 4);  // Insert 99 at index 1
    EXPECT_EQ(size, 3);
    EXPECT_TRUE(compareArrays(arr, expected, size));

    delete[] arr;
}

TEST(DynamicArrayTest, Erase1) {
    int size = 7;
    int *arr = new int[size]{1, 2, 3, 4, 5, 6, 7};

    int result = erase(arr, size, 2);  // Erase element at index 2
    int expected1[] = {1, 2, 4, 5, 6, 7};
    EXPECT_EQ(size, 6);
    EXPECT_EQ(result, 0);  // Should return 0 for success
    EXPECT_TRUE(compareArrays(arr, expected1, size));

    result = erase(arr, size, 0);  // Erase element at index 2
    int expected2[] = {2, 4, 5, 6, 7};
    EXPECT_EQ(size, 5);
    EXPECT_EQ(result, 0);  // Should return 0 for success
    EXPECT_TRUE(compareArrays(arr, expected2, size));

    result = erase(arr, size, 4);  // Erase element at index 2
    int expected3[] = {2, 4, 5, 6};
    EXPECT_EQ(size, 4);
    EXPECT_EQ(result, 0);  // Should return 0 for success
    EXPECT_TRUE(compareArrays(arr, expected3, size));

    delete[] arr;
}

TEST(DynamicArrayTest, Erase2) {
    int size = 3;
    int *arr = new int[size]{1, 2, 3};

    int result = erase(arr, size, 3);  // Invalid index
    EXPECT_EQ(result, -1);  // Should return -1

    result = erase(arr, size, -1);  // Invalid index
    EXPECT_EQ(result, -1);  // Should return -1

    delete[] arr;
}

TEST(DynamicArrayTest, Find1) {
    int size = 0;
    int *arr = new int[size]{ };

    EXPECT_EQ(find(arr, size, 30), -1);

    delete[] arr;
}

TEST(DynamicArrayTest, Find2) {
    int size = 6;
    int *arr = new int[size]{10, 20, 30, 40, 50, 20};

    EXPECT_EQ(find(arr, size, 30), 2);  // 30 is at index 2
    EXPECT_EQ(find(arr, size, 50), 4);  // 50 is at index 4
    EXPECT_EQ(find(arr, size, 10), 0);  // 30 is at index 2
    EXPECT_EQ(find(arr, size, 20), 1);  // 30 is at index 2

    delete[] arr;
}

TEST(DynamicArrayTest, FindNotExists) {
    int size = 4;
    int *arr = new int[size]{1, 2, 3, 4};

    EXPECT_EQ(find(arr, size, 99), -1);  // 99 is not in the array

    delete[] arr;
}