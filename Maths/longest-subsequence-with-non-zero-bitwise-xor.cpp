// Problem: Longest Subsequence With Non-Zero Bitwise XOR
// Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/
// Pattern: Bit Manipulation (XOR properties)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int res_xor = 0;
        bool allZero=true;
        for(int i:nums){
           res_xor=res_xor^i;
           if(i!=0)allZero=false;
        }
        if(allZero)return 0;
        return (res_xor==0)?n-1:n;
    }
    
};