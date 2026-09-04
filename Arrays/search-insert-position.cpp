// Problem: Search Insert Position
// Link: https://leetcode.com/problems/search-insert-position/description/
// Pattern: Binary Search (find leftmost insertion point)
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int low=0;
       int high=nums.size()-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }
       return low;
    }
};