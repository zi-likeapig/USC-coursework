#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(evaluateExpression,test1) {
    std::string expr="";
    EXPECT_EQ(evaluateExpression(expr),0);
}

TEST(evaluateExpression,test2) {
    std::string expr="   -1";
    EXPECT_EQ(evaluateExpression(expr),-1);
}

TEST(evaluateExpression,test3) {
    std::string expr="+1 - 1";
    EXPECT_EQ(evaluateExpression(expr),0);
}

TEST(evaluateExpression,test4) {
    std::string expr="1 +1+ 1-1";
    EXPECT_EQ(evaluateExpression(expr),2);
}

TEST(evaluateExpression,test5) {
    std::string expr="  +101-1+0 010";
    EXPECT_EQ(evaluateExpression(expr),110);
}

TEST(evaluateExpression,test6) {
    std::string expr="-19+18";
    EXPECT_EQ(evaluateExpression(expr),-1);
}