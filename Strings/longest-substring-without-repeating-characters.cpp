// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Pattern: Sliding Window + Hashing (last seen index tracking)
// Time: O(n) | Space: O(1)   [fixed 256 char hash array]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>hash(256,-1);
       int l=0,r=0;
       int maxlen=0;
       while(r<s.size()){
        if(hash[s[r]]!=-1){
          if(hash[s[r]]>=l)l=hash[s[r]]+1;
        }
        int len=r-l+1;
        maxlen=max(maxlen,len);
        hash[s[r]]=r;
        r++;
       }
       return maxlen;
    }
};