// Problem: Running Sum of 1d Array
// Link: https://leetcode.com/problems/running-sum-of-1d-array/description/
// Pattern: Prefix Sum (single pass)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>running;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           running.push_back(sum);
        }
        return running;
    }
};