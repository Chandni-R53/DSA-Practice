// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/description/
// Pattern: Kadane's Algorithm (track both min and max product)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestMax=nums[0];
        int bestMin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*bestMin;
            int v3=nums[i]*bestMax;
            bestMin=min(v1,min(v2,v3));
            bestMax=max(v1,max(v2,v3));
            ans=max(ans,max(bestMin,bestMax));
        }
        return ans;
    }
};