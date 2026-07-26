// Problem: Maximum Product of Three Numbers
// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/description/
// Pattern: Sorting + Greedy (two candidates: top 3 or two negatives + max)
// Time: O(n log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return max(
           nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]
        );
    }
};