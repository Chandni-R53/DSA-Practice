// Problem: Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// Pattern: Binary Search (parity-based index check)
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1])low=mid+2;
                else{high=mid;}
            }
            else{
                if(nums[mid]==nums[mid-1])low=mid+1;
                else{high=mid-1;}
            }
        }
        return nums[low];
    }
};