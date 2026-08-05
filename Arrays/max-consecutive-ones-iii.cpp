// Problem: Max Consecutive Ones III
// Link: https://leetcode.com/problems/max-consecutive-ones-iii/description/
// Pattern: Sliding Window (variable size, at most k zeros allowed)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int l=0,r=0;
        int zeros=0;
        while(r<nums.size()){
            if(nums[r]==0)zeros++;
            while(zeros>k){
              if(nums[l]==0)zeros--;
              l++;
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};