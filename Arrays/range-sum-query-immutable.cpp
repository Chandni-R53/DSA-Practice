// Problem: Range Sum Query - Immutable
// Link: https://leetcode.com/problems/range-sum-query-immutable/description/
// Pattern: Prefix Sum (precompute cumulative sum for O(1) range queries)
// Time: O(n) build | O(1) query | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class NumArray {
    vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size()+1);
        prefix[0]=0;
        for(int i=1;i<nums.size()+1;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};