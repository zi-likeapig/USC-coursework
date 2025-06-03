#include "q.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
// Implement each function of `q.h` here.

// Note: This function calls an auxiliary function
// called FindAllPasswords_aux.
std::unordered_set<std::string> FindAllPasswords(BlackBox& blackbox, int max_length) {
    std::unordered_set<std::string> results;
    std::string current_password="";
    FindAllPasswords_aux(blackbox, max_length, current_password, results);
    return results;
}

// A recursive function that finds all the correct valid_passwords that do not
// contain a word in the dictionary and puts them in the `results` parameter.
void FindAllPasswords_aux(BlackBox& blackbox, int max_length, std::string& current_password, 
                          std::unordered_set<std::string>& results) {
    if(current_password.size()<=max_length && current_password.size()>0) {
        if(blackbox.TryPassword(current_password)) {
            //std::cout<<"now string is: "<<current_password<<"\n";
            if(!blackbox.IsInDictionary(current_password)) {
                //std::cout<<" ---------and it is valid\n";
                results.insert(current_password);
            }
        }
        if(current_password.size()==max_length) return;
    }

    for(int i=0;i<26;i++) {
        current_password.push_back('a'+i);
        FindAllPasswords_aux(blackbox, max_length, current_password, results);
        current_password.pop_back();
    }
    return;
}