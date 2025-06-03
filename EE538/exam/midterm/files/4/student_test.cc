#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(MyVector, DefaultConstructor_and_copy) {
    MyVector vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    MyVector copyVec = vec;
    EXPECT_EQ(copyVec.size(), vec.size());
    EXPECT_EQ(copyVec.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, ConstructorWithSize) {
    MyVector vec(5);
    EXPECT_EQ(vec.size(), 5);
    for (int val : vec.ConvertToStdVector()) {
        EXPECT_EQ(val, 0);
    }
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, Copy_and_pushback) {
    MyVector vec(3);
    vec.push_back(10);
    vec.push_back(20);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.at(0), 0);
    EXPECT_EQ(vec.at(1), 0);
    EXPECT_EQ(vec.at(2), 0);
    EXPECT_EQ(vec.at(3), 10);
    EXPECT_EQ(vec.at(4), 20);

    MyVector copyVec = vec;
    EXPECT_EQ(copyVec.size(), vec.size());
    EXPECT_EQ(copyVec.at(0), 0);
    EXPECT_EQ(copyVec.at(1), 0);
    EXPECT_EQ(copyVec.at(2), 0);
    EXPECT_EQ(copyVec.at(3), 10);
    EXPECT_EQ(copyVec.at(4), 20);
}

TEST(MyVector, PushFront) {
    MyVector vec(2);
    vec.push_front(10);
    vec.push_front(20);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec.at(0), 20);
    EXPECT_EQ(vec.at(1), 10);
    EXPECT_EQ(vec.at(2), 0);
    EXPECT_EQ(vec.at(3), 0);
}

TEST(MyVector, PopBack) {
    MyVector vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.pop_back(), 20);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    EXPECT_EQ(vec.pop_back(), 10);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    EXPECT_EQ(vec.pop_back(), -1);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kPopFromEmptyVector);
}

TEST(MyVector, PopFront) {
    MyVector vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.pop_front(), 10);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    EXPECT_EQ(vec.pop_front(), 20);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    EXPECT_EQ(vec.pop_front(), -1);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kPopFromEmptyVector);
}

TEST(MyVector, Insert_empty) {
    MyVector vec;
    vec.insert(15, -1);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.at(0), 15);
}

TEST(MyVector, Insert_back) {
    MyVector vec(2);
    vec.insert(15, 1);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.at(0), 0);
    EXPECT_EQ(vec.at(1), 0);
    EXPECT_EQ(vec.at(2), 15);
}

TEST(MyVector, Insert_minesone) {
    MyVector vec(2);
    vec.insert(15, -1);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.at(0), 15);
    EXPECT_EQ(vec.at(1), 0);
    EXPECT_EQ(vec.at(2), 0);
}

TEST(MyVector, Insert_valid) {
    MyVector vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.insert(15, 0);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.at(1), 15);
    EXPECT_EQ(vec.at(2), 20);
}

TEST(MyVector, Insert_invalid) {
    MyVector vec;
    vec.insert(15, -2);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kIndexError);

    vec.insert(1,-1);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
    EXPECT_EQ(vec.at(0), 1);

    vec.insert(2,0);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);

    vec.insert(5,3);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec.get_error(), ErrorCode::kIndexError);
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);
}

TEST(MyVector, At) {
    MyVector vec;
    EXPECT_EQ(vec.at(0), -1);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kIndexError);

    vec.push_back(10);
    vec.push_back(20);
    EXPECT_EQ(vec.size(), 2);

    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
    EXPECT_EQ(vec.at(2), -1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kIndexError);
    EXPECT_EQ(vec.at(1), 20);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
    EXPECT_EQ(vec.at(-1), -1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kIndexError);
}

TEST(MyVector, Find) {
    MyVector vec;
    EXPECT_EQ(vec.find(10), -1);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNotFound);

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(10);
    EXPECT_EQ(vec.size(), 3);

    EXPECT_EQ(vec.find(10), 0); //first
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);
    EXPECT_EQ(vec.find(20), 1);
    EXPECT_EQ(vec.get_error(), ErrorCode::kNoError);

    EXPECT_EQ(vec.find(30), -1);  // Not found
    EXPECT_EQ(vec.get_error(), ErrorCode::kNotFound);
}

TEST(MyVector, GetError) {
    MyVector vec;
    vec.pop_back();
    EXPECT_EQ(vec.get_error(), ErrorCode::kPopFromEmptyVector);
}

TEST(MyVector, ConvertToStdVector) {
    MyVector vec;
    vec.push_back(10);
    vec.push_back(20);
    std::vector<int> v = vec.ConvertToStdVector();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
}