#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

bool CanBecome(const std::string &s, const std::string &goal) {
    if(s.size()!=goal.size())
        return false;
    if(s.size()==0)
        return true;
    int len=s.size();
    for(int i=0;i<len;i++) {
        if(goal[i]==s[0]) {
            bool same=true;
            for(int j=0;j<len;j++) {
                if(goal[(i+j)%len]!=s[j])
                    same=false;
            }
            if(same==true) return true;
        }
    }
    return false;
}
