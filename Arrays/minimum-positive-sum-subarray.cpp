// Problem: Minimum Positive Sum Subarray with Length Between L and R 
// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/
// Pattern: Brute Force, running sum (prefix-style accumulation)
// Time: O(n^2) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                int len=j-i+1;
                sum+=nums[j];
                if((len>=l&&len<=r)&&sum>0){
                    ans=min(ans,sum);
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};