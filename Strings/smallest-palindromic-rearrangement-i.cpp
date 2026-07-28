// Problem: Smallest Palindromic Rearrangement I
// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// Pattern: Greedy + Two Pointer (sort first half, mirror to second)
// Time: O(n log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int mid=n/2;
        sort(s.begin(),s.begin()+mid);
        int i=0,j=n-1;
        while(i<j){
            s[j]=s[i];
            i++;
            j--;
        }
        return s;
    }
};