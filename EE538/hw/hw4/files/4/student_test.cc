#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(StudentMaxHeapTest, PushAndTop) {
    StudentMaxHeap heap;
    heap.push(Student("Alice", 85));
    heap.push(Student("Bob", 95));
    heap.push(Student("Carol", 75));

    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.top().name, "Bob");
    EXPECT_EQ(heap.top().grade, 95);
}

TEST(StudentMaxHeapTest, PopAndTop) {
    StudentMaxHeap heap;
    heap.push(Student("A", 50));
    heap.push(Student("B", 100));
    heap.push(Student("C", 80));

    std::vector<Student> data=heap.GetData();
    for(int j=0;j<heap.size();j++) {
        cout<<data[j].grade<<endl;
    }

    EXPECT_EQ(heap.top().grade, 100);
    EXPECT_TRUE(heap.pop());
    EXPECT_EQ(heap.top().grade, 80);
    EXPECT_TRUE(heap.pop());
    EXPECT_EQ(heap.top().grade, 50);
    EXPECT_TRUE(heap.pop());
    EXPECT_FALSE(heap.pop());
    EXPECT_TRUE(heap.empty());
}

TEST(StudentMaxHeapTest, IndexHelpers) {
    StudentMaxHeap heap;
    heap.push(Student("S0", 10));
    heap.push(Student("S1", 10));
    heap.push(Student("S2", 20));
    heap.push(Student("S3", 30));
    heap.push(Student("S4", 40));
    heap.push(Student("S5", 50));
    heap.push(Student("S6", 60));
    heap.push(Student("S7", 70));
    heap.push(Student("S8", 80));
    heap.push(Student("S9", 90));

    EXPECT_EQ(heap.GetParentIndex(0), INT_MAX);
    EXPECT_EQ(heap.GetLeftIndex(0), 1);
    EXPECT_EQ(heap.GetRightIndex(0), 2);

    EXPECT_EQ(heap.GetParentIndex(1), 0);
    EXPECT_EQ(heap.GetLeftIndex(1), 3);
    EXPECT_EQ(heap.GetRightIndex(1), 4);

    EXPECT_EQ(heap.GetParentIndex(2), 0);
    EXPECT_EQ(heap.GetLeftIndex(2), 5);
    EXPECT_EQ(heap.GetRightIndex(2), 6);

    EXPECT_EQ(heap.GetParentIndex(3), 1);
    EXPECT_EQ(heap.GetLeftIndex(3), 7);
    EXPECT_EQ(heap.GetRightIndex(3), 8);

    EXPECT_EQ(heap.GetParentIndex(4), 1);
    EXPECT_EQ(heap.GetLeftIndex(4), 9);
    EXPECT_EQ(heap.GetRightIndex(4), INT_MAX);

    EXPECT_EQ(heap.GetParentIndex(5), 2);
    EXPECT_EQ(heap.GetLeftIndex(5), INT_MAX);
    EXPECT_EQ(heap.GetRightIndex(5), INT_MAX);

    EXPECT_EQ(heap.GetParentIndex(6), 2);
    EXPECT_EQ(heap.GetLeftIndex(6), INT_MAX);
    EXPECT_EQ(heap.GetRightIndex(6), INT_MAX);

    EXPECT_EQ(heap.GetParentIndex(7), 3);
    EXPECT_EQ(heap.GetLeftIndex(7), INT_MAX);
    EXPECT_EQ(heap.GetRightIndex(7), INT_MAX);

    EXPECT_EQ(heap.GetParentIndex(8), 3);
    EXPECT_EQ(heap.GetLeftIndex(8), INT_MAX);
    EXPECT_EQ(heap.GetRightIndex(8), INT_MAX);

    EXPECT_EQ(heap.GetParentIndex(9), 4);
    EXPECT_EQ(heap.GetLeftIndex(9), INT_MAX);
    EXPECT_EQ(heap.GetRightIndex(9), INT_MAX);

}

TEST(StudentMaxHeapTest, ConstructFromVector) {
    std::vector<Student> input = {
        Student("A", 50),
        Student("B", 70),
        Student("C", 90),
        Student("D", 20)
    };
    StudentMaxHeap heap(input);
    EXPECT_EQ(heap.top().grade, 90);
}

TEST(HeapSortTest, BasicSort) {
    std::vector<Student> input = {
        Student("B", 88),
        Student("C", 75),
        Student("A", 95),
        Student("D", 60)
    };

    HeapSort(input);

    EXPECT_EQ(input[0].grade, 60);
    EXPECT_EQ(input[1].grade, 75);
    EXPECT_EQ(input[2].grade, 88);
    EXPECT_EQ(input[3].grade, 95);
}