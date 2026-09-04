// Problem: Find First and Last Position of Element in Sorted Array
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Pattern: Binary Search (two passes — leftmost and rightmost occurrence)
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findfirst(int l,int h,int target,vector<int>& nums){
        int res=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target)h=mid-1;
            else{
                res=mid;
                h=mid-1;
            }
        }
        return res;
    }
    int findlast(int l,int h,int target,vector<int>& nums){
        int res=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target)h=mid-1;
            else{
                res=mid;
                l=mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int low=0;
        int high=nums.size()-1;
        int v1=findfirst(low,high,target,nums);
        int v2=findlast(low,high,target,nums);
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};