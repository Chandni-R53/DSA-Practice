// Problem: Valid Palindrome II
// Link: https://leetcode.com/problems/valid-palindrome-ii/description/
// Pattern: Two Pointer (skip one char from left or right on mismatch)
// Time: O(n) | Space: O(n)   [substr creates new strings]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string sub){
       int i=0;
       int j=sub.size()-1;
       while(i<j){
        if(sub[i]!=sub[j])return false;
        i++;
        j--;
       }
       return true;
    } 

    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
          if(s[i]!=s[j]){
            bool iskip=check(s.substr(i+1,j-i));
            bool jskip=check(s.substr(i,j-i));
            if(iskip || jskip)return true;
            else return false;
          }
          i++;
          j--;
        }
        return true;
    }
};