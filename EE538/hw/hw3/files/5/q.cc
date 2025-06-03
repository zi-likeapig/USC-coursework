#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <stack>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//  Given an expression string, find if the input has valid brackets (i.e. { }
//  or [ ] or ( ) ).
// An input expression is valid if:
// Open brackets are closed by the same type of brackets. Open brackets must
// be closed in the correct order. An empty string is also considered valid.
// You should only check for the validity of brackets based on the above
// rules, i.e. ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’, not the rest of the expression.
// Example 1: Input: "(a+b)" Output: true
// Example 2: Input: "(a+b)[c*d]{5g+h}" Output: true
// Example 3: Input: "(a+b]" Output: false
// Example 4: Input: "(7h+[5c)+7]" Output: false
// Example 5: Input: "{2k+[5j]}" Output: true
// Example 6: Input: "{2k++[5--*j]}" Output: true
bool CPPLib::CheckValidExpression(const std::string& input) {
    std::map<char,char> brackets={ {')','('}, {']','['}, {'}','{'} };
    std::stack<char> s;
    for(auto c : input) {
        // std::cout<<c<<std::endl;
        if(c=='(' || c=='[' || c=='{') s.push(c);
        if(brackets.count(c)) {
            // std::cout<<"end:"<<c<<std::endl;
            if(s.empty() || s.top()!=brackets[c]) return false;
            else s.pop();
        }
    }
    return s.empty();
}

// Checks if a string is a palindrome.
// An empty string is a palindrome.
// A non empty string is a palindrome if it is equal to its reverse string.

// Example 1: Input: "aba", output: true
// Example 2: Input: "abba", output: true

// You cannot use any std:: function.
// Your memory usage should be O(1).
bool CPPLib::IsPalindrome(const std::string& input) {
    if(input.empty()) return true;
    int len=input.size();
    for(int i=0;i<len/2;i++) {
        //std::cout<<input[i]<<std::endl;
        if(input[i]!=input[len-1-i]) return false;
    }
    return true;
}

// Given a string, every letter appears even number of times except for one.
// Find that letter!

// Any solution that work is acceptable, but see if you can implement it while
// keeping your memory usage as O(1).
int CPPLib::OddChar(const std::string& input) {
    std::map<char,int> letter;
    for(auto c : input) {
        letter[c]++;
        /*if(!letter.count(c)) letter[c]=true;
        else {
            letter[c]=~letter[c];
        }*/
    }
    for(auto p : letter) {
        if(p.second%2) return p.first;
    }
    //return 0;
}