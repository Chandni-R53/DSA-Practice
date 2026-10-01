// Problem: Find the Smallest Divisor Given a Threshold
// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Pattern: Binary Search on Answer (find the minimum divisor where sum of ceil(nums[i]/d) <= threshold)
// Time: O(n log(max(nums))) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divisor(vector<int> nums, int mid){
       int res=0;
       for(int i=0;i<nums.size();i++){
        nums[i]=ceil((1LL*nums[i]+mid-1)/mid);
        res+=nums[i];
       }
       return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
           int mid=low+(high-low)/2;
           int val=divisor(nums,mid);
           if(val<=threshold){
            high=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        return low;
    }
};