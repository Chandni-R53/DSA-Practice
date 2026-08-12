// Problem: Length of Longest Subarray With at Most K Frequency
// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
// Pattern: Sliding Window + HashMap (frequency tracking)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxlen=0;
        unordered_map<int,int>m;
        int l=0,r=0;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m[nums[r]]>k){
              m[nums[l]]--;
              l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};