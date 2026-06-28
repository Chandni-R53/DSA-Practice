// Problem: Sum of Subarray Ranges
// Link: https://leetcode.com/problems/sum-of-subarray-ranges/
// Pattern: Brute Force + Running Minimum & Maximum
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           int mn=INT_MAX;
           int mx=INT_MIN;
           for(int j=i;j<n;j++){
            mn=min(mn,nums[j]);
            mx=max(mx,nums[j]);
            sum+=(mx-mn);
            }
        
        }
        return sum;
    }
};