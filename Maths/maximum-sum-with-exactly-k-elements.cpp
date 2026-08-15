// Problem: Maximum Sum With Exactly K Elements
// Link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/
// Pattern: Greedy + Math (arithmetic series from max)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int score=0;
        int mx=*max_element(nums.begin(),nums.end());
        while(k>0){
           score+=mx;
           mx=mx+1;
           k--;
        }
        return score;
    }
};