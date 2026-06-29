// Problem: Number of Strings That Appear as Substrings in Word
// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Pattern: String Matching (built-in find)
// Time: O(n * m) | Space: O(1)   [n = patterns size, m = avg pattern length]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string i:patterns){
            if(word.find(i)!=string::npos)count++;
        }
        return count;
    }
};