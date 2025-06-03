#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.

// Given a vector of weights and values and an integer value representing total
// capacity of a knapsack, implement the following function.

// The knapSack01NoDynamicProgramming function does not use Dynamic Programming
// and it is not a recursive function. Instead it calls a recursive function
// knapSack01NoDynamicProgramming_Helper (which is also not using dynamic
// programming).

// 1. Implement knapSack01NoDynamicProgramming:
int knapSack01NoDynamicProgramming(const std::vector<int> &weights, const std::vector<int> &values, int w) {
    if(w==0) return 0;
    return knapSack01NoDynamicProgramming_Helper(weights, values, w, 0);
}

// 2. Define knapSack01NoDynamicProgramming_Helper and implement it in the .cc
// file. This function has takes similar arguments like
// knapSack01NoDynamicProgramming with some extra helper parameters:
int knapSack01NoDynamicProgramming_Helper(const std::vector<int> &weights, 
                                          const std::vector<int> &values, int w, int i) {
    /*if(i==weights.size()-1) {
        if(w>=weights[i]) return values[i];
        else return 0;
    }*/
    if(i==weights.size()) return 0;
    
    if(w>=weights[i]) {
        return std::max(knapSack01NoDynamicProgramming_Helper(weights, values, w, i+1),
                        knapSack01NoDynamicProgramming_Helper(weights, values, w-weights[i], i+1)+values[i]);
    }
    else return knapSack01NoDynamicProgramming_Helper(weights, values, w, i+1);
}

//-----------------------------------------------------------------------------
// 3. Implement knapSack01Memo:

// The knapSack01Memo function itself doesn't use a memo. It's just a wrapper
// around knapSack01Memo_Helper.
int knapSack01Memo(const std::vector<int> &weights, const std::vector<int> &values, int w) {
    if(w==0) return 0;
    std::vector<std::vector<int>> memo(weights.size(), std::vector<int>(w+1,-1));
    return knapSack01Memo_Helper(weights, values, w, 0, memo);
}

// 4. Implement knapSack01Memo_Helper. This function has takes similar arguments
// like knapSack01Memo with some extra helper parameters such as i and memo,
// which is a two-dimensional vector:
int knapSack01Memo_Helper(const std::vector<int> &weights, const std::vector<int> &values, 
                          int w, int i, std::vector<std::vector<int>> &memo) {
    if(i==weights.size()) return 0;
    if(memo[i][w]!=-1) return memo[i][w];
    if(w>=weights[i]) {
        memo[i][w]=std::max(knapSack01Memo_Helper(weights, values, w, i+1, memo),
                            knapSack01Memo_Helper(weights, values, w-weights[i], i+1, memo)+values[i]);
    }
    else memo[i][w]=knapSack01Memo_Helper(weights, values, w, i+1, memo);
    return memo[i][w];
}
//-----------------------------------------------------------------------------
// 3. Implement knapSack01Tablulation. Use a two-dimensional vector for the
// table.
int knapSack01Tablulation(const std::vector<int> &weights, const std::vector<int> &values, int w) {
    if(w==0) return 0;
    if(weights.size()==0) return 0;
    std::vector<std::vector<int>> tab(weights.size(), std::vector<int>(w+1,0));
    for(int i=weights[0];i<w+1;i++) 
        tab[0][i]=values[0];

    for(int i=1;i<weights.size();i++) {
        for(int cap=1;cap<w+1;cap++) {
            if(cap>=weights[i]) {
                tab[i][cap]=std::max(tab[i-1][cap],tab[i-1][cap-weights[i]]+values[i]);
            }
            else tab[i][cap]=tab[i-1][cap];
        }
    }
    return tab[weights.size()-1][w];
}
