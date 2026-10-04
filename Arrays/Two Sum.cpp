// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/description/
// Pattern: HashMap (complement lookup, single pass)
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
         int val=target-nums[i];
         if(m.find(val)!=m.end())return {m[val],i};
         m[nums[i]]=i;
       }
       return {-1,-1};
    }
};