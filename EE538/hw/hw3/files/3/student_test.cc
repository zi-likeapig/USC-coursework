#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(QueueTest, CopyConstructor) {
    Queue q1;
    EXPECT_TRUE(q1.IsEmpty());

    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    EXPECT_EQ(q1.Front(), 1);
    EXPECT_FALSE(q1.IsEmpty());

    Queue q2(q1);

    EXPECT_EQ(q2.Front(), 1);
    EXPECT_FALSE(q2.IsEmpty());
}

TEST(QueueTest, CopyAssignment) {
    Queue q1, q2;
    q1.Enqueue(10);
    q1.Enqueue(20);
    EXPECT_EQ(q1.Front(), 10);
    EXPECT_FALSE(q1.IsEmpty());

    q2 = q1;

    EXPECT_EQ(q2.Front(), 10);
    EXPECT_FALSE(q2.IsEmpty());
}

TEST(QueueTest, OperatorPlus) {
    Queue q1, q2;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    q2.Enqueue(4);
    q2.Enqueue(5);

    Queue q3 = q1 + q2;
    std::vector<int> expected = {4, 5, 1, 2, 3};
    EXPECT_EQ(q3.GetData(), expected);
}

TEST(QueueTest, Enqueue) {
    Queue q;
    EXPECT_TRUE(q.Enqueue(42));
    EXPECT_TRUE(q.Enqueue(12));
    EXPECT_EQ(q.Front(), 42);
}

TEST(QueueTest, Dequeue) {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    
    EXPECT_TRUE(q.Dequeue());
    EXPECT_EQ(q.Front(), 20);
    EXPECT_FALSE(q.IsEmpty());

    EXPECT_TRUE(q.Dequeue());
    EXPECT_EQ(q.Front(), -1);
    EXPECT_TRUE(q.IsEmpty());

    EXPECT_FALSE(q.Dequeue());
}

TEST(QueueTest, IsEmpty) {
    Queue q;
    EXPECT_TRUE(q.IsEmpty());
    
    q.Enqueue(5);
    EXPECT_FALSE(q.IsEmpty());

    q.Dequeue();
    EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, Front) {
    Queue q;
    EXPECT_EQ(q.Front(), -1); 

    q.Enqueue(99);
    EXPECT_EQ(q.Front(), 99);
}

