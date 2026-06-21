// Problem: Minimum Consecutive Cards to Pick Up
// Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
// Pattern: HashMap (last seen index)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>m;
        int len=INT_MAX;
        for(int i=0;i<cards.size();i++){
            int n=cards[i];
            if(m.find(n)!=m.end()){
                len=min(len,i-m[n]+1);
            }
            m[cards[i]]=i;
        }      
        if(len==INT_MAX){
            return -1;
        }
        else{
            return len;
        }
    }
};