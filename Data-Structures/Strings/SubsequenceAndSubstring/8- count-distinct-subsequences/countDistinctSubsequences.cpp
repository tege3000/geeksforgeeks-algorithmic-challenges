/*
 * Topic: Count Distinct Subsequences
 *
 * Description: Given a string, find the count
 * of distinct subsequences of it.
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

// For a string of numbers, get all subsequences
// NOTE: This is a naive approach, learn better way later.
vector <string> getAllSubsequences(string s) {
    vector<string> subsequences;
    
    // for n characters, there are 2^n possibilities
    int numSubs = pow(2, s.size());
    
    vector<vector<int>> truthTable;
    for(int i = 0; i < numSubs; i++) {
        vector <int> inner;
        for(int j = 0; j < s.size(); j++) {
            inner.push_back(0);
        }
        truthTable.push_back(inner);
    }
    
    // generate truth table
    for(int i = 0; i < s.size(); i++) {
        int numRecurring = pow(2, s.size()-(i+1));
        int start = 0;
        int end = numRecurring;
        for(int j = 0; j < pow(2, i+1); j++) {
            end = numRecurring + start;
            if(j % 2 == 0) {
                // fill up with zeros
                for(int k = start; k < end; k++) {
                    truthTable[k][i] = 0;
                }
            }
            else {
                // fill up with 1s
                for(int k = start; k < end; k++) {
                    truthTable[k][i] = 1;
                }
            }
            
            start += numRecurring;
        }
    }
    
    for(int i = 0; i < numSubs; i++) {
        string num = "";
        for(int j = 0; j < s.size(); j++) {
            if(truthTable[i][j] == 1) {
                num += s[j];
            }
        }
        
        if(num.size() >= 1) {
            subsequences.push_back(num);
        }
    }
    
    return subsequences;
}

// NOTE: This includes empty substring
// Naive Solution
int countDistinctSubsequences(string a) {
    // get all subsequences first
    vector<string> allSubsequences = getAllSubsequences(a);
    
    set<string> distinct;
    for(int i = 0; i < allSubsequences.size(); i++) {
        distinct.insert(allSubsequences[i]);
    }
    
    return distinct.size()+1;
}

int main() {
    string a = "gfg";
    cout << countDistinctSubsequences(a) << endl;
    
    string a2 = "ggg";
    cout << countDistinctSubsequences(a2) << endl;
    
    return 0;
}

