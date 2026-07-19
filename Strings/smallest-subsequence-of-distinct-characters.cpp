// Problem: Smallest Subsequence of Distinct Characters
// Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
// Pattern: Greedy + Monotonic Stack (last occurrence tracking)
// Time: O(n) | Space: O(1)   [at most 26 unique chars]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        vector<int>lastIdx(26);
        vector<bool>vis(26,false);
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            lastIdx[c-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(vis[c-'a']==true)continue;
            while(ans.size()>0 && ans.back()>c && lastIdx[ans.back()-'a']>i){
               vis[ans.back()-'a']=false;
               ans.pop_back();
            }
            ans.push_back(c);
            vis[c-'a']=true;
        }
        return ans;
    }
};