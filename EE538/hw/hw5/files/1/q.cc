#include "q.h"

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <climits>
// Implement each function of `q.h` here.

// Given a non-negative integer n, Implement a function that calculates the
// n(th) Fibonacci number.

// Your implementation should have a worst case runtime complexity of O(n) and
// memory complexity of O(1).
int Fibonacci(int n) {
    int a=1,b=1;
    if(n<0) return 1;
    if(n==0) return a;
    if(n==1) return b;
    for(int i=2;i<=n;i++) {
        std::swap(a,b);
        b+=a;
    }
    return b;
}

//-----------------------------------------------------------------------------
// Remember the Coin Change Problem:

// Given n different coin types and an integer representing the total amount of
// money, find the minimum number of coins to make up that amount. You can use
// as many coins as you want from each coin type.

// Example:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
//-----------------------------------------------------------------------------

// Implement a function that calculates the minimum number and use memoization
// but with a twist: you are only allowed to use an std::list for the memo (Do
// not use map, unordered_map, set, vector, or array).

// CoinChangeMemo is not a recursive function, but it is a wrapper around
// CoinChangeMemo_Helper that is recursive. Use std::list<int> for memo.
int CoinChangeMemo(std::vector<int>& coins, int amount) {
    if(amount<0) return -1;
    std::list<int> memo(amount+1,amount+1);
    int ans=CoinChangeMemo_Helper(coins,amount,memo);
    return ans!=amount+1 ? ans : -1;
}

int CoinChangeMemo_Helper(std::vector<int>& coins, int amount, std::list<int>& memo) {
    if(amount==0) return 0;
    
    auto it=memo.begin();
    advance(it,amount);
    if(*it<=amount) return *it;

    for(auto& coin:coins) {
        if(amount>=coin) {
            *it=std::min(*it,CoinChangeMemo_Helper(coins,amount-coin,memo)+1);
        }
    }
    return *it;
}

//-----------------------------------------------------------------------------
// Implement a function that calculates the minimum number and use tabulation
// but with a twist: you are only allowed to use an std::list for the table
// inside this function (Do not use map, unordered_map, set, vector, or array):
int CoinChangeTabulation(std::vector<int>& coins, int amount) {
    if(amount<0) return -1;
    std::list<int> tab(amount+1,amount+1);
    auto it=tab.begin();
    *it=0;
    for(int i=1;i<=amount;i++) {
        it++;
        for(auto coin:coins) {
            if(i>=coin) {
                auto it_=tab.begin();
                advance(it_,i-coin);
                *it=std::min(*it, *it_+1);
            }
        }
    }
    return *it!=amount+1 ? *it : -1;
}