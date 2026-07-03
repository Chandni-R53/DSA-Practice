// Problem: Move Zeroes
// Link: https://leetcode.com/problems/move-zeroes/description/
// Pattern: Two Pointer (in-place, single pass)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[idx]);
            idx++;
        }
       }
    }
};