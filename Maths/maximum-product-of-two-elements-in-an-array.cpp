// Problem: Maximum Product of Two Elements in an Array
// Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
// Pattern: Brute Force (nested loop, pair enumeration)
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans=max(ans,(nums[i]-1)*(nums[j]-1));
            }
        }
        return ans;
    }
};