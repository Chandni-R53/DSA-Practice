// Problem: Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/description/
// Pattern: Prefix Sum (total sum - left sum - current = right sum)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int sum=0;
        for(int i:nums){sum+=i;}
        for(int i=0;i<nums.size();i++){
            int right=sum-left-nums[i];
            if(left==right)return i;
            left+=nums[i];
        }
        return -1;
    }
};