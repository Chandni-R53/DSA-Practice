// Problem: Maximum Length Substring With Two Occurrences
// Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
// Pattern: Sliding Window (fixed frequency limit, at most 2 occurrences)
// Time: O(n) | Space: O(1)   [fixed 26 char hash array]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen=0;
        int l=0,r=0;
        vector<int>hash(26,0);
        while(r<s.size()){
            hash[s[r]-'a']++;
            while(hash[s[r]-'a']>2){
               hash[s[l]-'a']--;
               l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};