// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/description/
// Pattern: Single Pass (linear scan, reset on zero)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count=0;
            else count++;
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};