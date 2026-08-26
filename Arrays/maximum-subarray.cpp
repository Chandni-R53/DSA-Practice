// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/description/
// Pattern: Kadane's Algorithm (dynamic programming, local vs global max)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            best=max(nums[i],best+nums[i]);
            ans=max(ans,best);
        }
        return ans;
    }
};