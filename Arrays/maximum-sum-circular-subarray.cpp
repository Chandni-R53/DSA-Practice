// Problem: Maximum Sum Circular Subarray
// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/description/
// Pattern: Kadane's Variant (max subarray + min subarray for circular case)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;
        int maxSum=nums[0];
        int minSum=nums[0];
        int maxans=nums[0];
        int minans=nums[0];
        for(int i=1;i<nums.size();i++){
           maxSum=max(nums[i],maxSum+nums[i]);
           maxans=max(maxans,maxSum);
           minSum=min(nums[i],minSum+nums[i]);
           minans=min(minans,minSum);
        }
        if(maxans<0)return maxans;
        return max(maxans,sum-minans);
    }
};