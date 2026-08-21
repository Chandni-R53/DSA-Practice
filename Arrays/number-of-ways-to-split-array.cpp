// Problem: Number of Ways to Split Array
// Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/
// Pattern: Prefix Sum (running left sum vs remaining right sum)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int splitCount=0;
        long long left=0;
        long long sum=0;
        for(int i:nums)sum+=i;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            long long right=sum-left;
           if(left>=right)splitCount++;
        }
        return splitCount;
    }
};