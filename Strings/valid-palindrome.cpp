// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/description/
// Pattern: Two Pointer (filter + converging pointers)
// Time: O(n) | Space: O(n)   [O(n) for filtered string res]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        int i=0;
        while(i<s.size()){
            char c=s[i];
            if(c>='A'&&c<='Z'){
                c=tolower(c);
            }
            if(c>='a'&&c<='z' || c>='0'&&c<='9'){
                res+=c;
            }
            i++;
        }
        int k=0,j=res.size()-1;
        while(k<j){
            if(res[k]!=res[j])return false;
            k++;
            j--;
        }
        return true;
    }
};