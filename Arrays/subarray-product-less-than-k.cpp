// Problem: Subarray Product Less Than K
// Link: https://leetcode.com/problems/subarray-product-less-than-k/description/
// Pattern: Sliding Window (variable size, shrink from left)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int count=0;
        int l=0,r=0;
        long long product=1;
        while(r<nums.size()){
            product*=nums[r];
            while(product>=k){
                product/=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};