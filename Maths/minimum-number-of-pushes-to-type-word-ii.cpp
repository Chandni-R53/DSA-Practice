// Problem: Minimum Number of Pushes to Type Word II
// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
// Pattern: Greedy + Sorting (sort by frequency, assign to keys)
// Time: O(n + 26 log 26) → O(n) | Space: O(1)   [fixed 26 char freq array]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int pushCount=0;
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0;i<freq.size();i++){
            while(freq[i]>0){
                pushCount+=i/8+1;
                freq[i]--;
            }
        }
        return pushCount;
    }
};