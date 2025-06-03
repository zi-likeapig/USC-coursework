#include <iostream>
#include <list>
#include <string>
#include <vector>

// TODO:
// 1. Implement the following functions in q.cc.
// 2. Write some unit tests for them in student_test.cc

//-----------------------------------------------------------------------------
// Rules for climbing stairs:
// You are climbing a staircase. Each time you can either climb 1 or 2 or 3
// steps. It takes n steps to reach the top. Your function takes n as input.
// Given a non-negative integer n, calculate how many distinct ways you can
// climb to the top. Your function should accept positive numbers less than 45
// and return the number of ways.

// If there are 0 stairs, return 0. For negative input, please
// return -1.
// For example, if the stairs number is 3, (n = 3), it should have 4 ways to the
// top:

// 1 + 1 + 1

// 1 + 2

// 2 + 1

// 3


// Please implement the function using recursion.
int ClimbStairs(int n);
//-----------------------------------------------------------------------------

