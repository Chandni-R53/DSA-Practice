// Problem: Find the Index of the First Occurrence in a String
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Pattern: String Matching (sliding window / brute force)
// Time: O(n*m) | Space: O(1)

#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
       int h=haystack.size();
       int n=needle.size();
       int idx=h-n;
       for(int i=0;i<=idx;i++){
        bool match=true;
        int j=0;
        while(j<n){
            if(needle[j]!=haystack[i+j]){
              match=false;
              break;
            }
            j++;
        }
        if(match){
            return i;
        }
       }
       return -1;
    }
};