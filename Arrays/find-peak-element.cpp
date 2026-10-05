// Problem: Find Peak Element
// Link: https://leetcode.com/problems/find-peak-element/description/
// Pattern: Binary Search (converge toward peak, eliminate downhill side)
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};