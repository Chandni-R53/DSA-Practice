// Problem: 3Sum Closest
// Link: https://leetcode.com/problems/3sum-closest/description/
// Pattern: Two Pointer (sort + fix one + converging pointers)
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int bestSum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-bestSum))bestSum=sum;
                if(sum<target)j++;
                else if(sum>target)k--;
                else return sum;
            }
        }
        return bestSum;
    }
};