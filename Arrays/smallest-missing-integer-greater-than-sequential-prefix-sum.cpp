// Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
// Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum
// Pattern: Prefix Sum + Linear Search
// Time: O(n²) | Space: O(1)   [find() is O(n) called in a loop]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum=nums[0];
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]+1){
            prefixSum+=nums[i];
           }
           else break;
        }
        while(find(nums.begin(),nums.end(),prefixSum)!=nums.end()){
            prefixSum+=1;
        }
        return prefixSum;
    }
};