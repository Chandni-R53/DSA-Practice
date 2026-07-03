// Problem: Squares of a Sorted Array
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/
// Pattern: Two Pointer (converging, fill from end)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        int idx=n-1;
        int i=0;
        int j=n-1;
        while(i<=j){
            int val=0;
            if(abs(nums[i])>abs(nums[j])){
              val=nums[i];
              i++;
            }
            else{
                val=nums[j];
                j--;
            }
            v[idx]=val*val;
            idx--;
        }
        return v;
    }
};