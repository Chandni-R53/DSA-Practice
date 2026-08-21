// Problem: Shuffle the Array
// Link: https://leetcode.com/problems/shuffle-the-array/description/
// Pattern: Array Manipulation (interleave two halves)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr;
        int j=n;
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
            j++;
            
        }
        return arr;
    }
};