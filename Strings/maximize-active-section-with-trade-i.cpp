// Problem: Maximize Active Section with Trade I
// Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/
// Pattern: Greedy + Sliding Window (consecutive zero group merging)
// Time: O(n) | Space: O(n)   [zeroes vector stores zero-group lengths]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count=0;
        for(char c:s){
            if(c=='1')count++;
        }
        vector<int>zeroes;
        int sum=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='0'){
                int start=i;
                while(i<s.size()&&s[i]=='0')i++;
                zeroes.push_back(i-start);
            }
            else{i++;}
        }
        for(int i=1;i<zeroes.size();i++){
           sum=max(sum,zeroes[i-1]+zeroes[i]);
        }
        return sum+count;
    }
};