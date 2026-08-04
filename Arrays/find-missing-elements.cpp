// Problem: Find Missing Elements
// Link: https://leetcode.com/problems/find-missing-elements/description/
// Pattern: Brute Force (linear search for each value in range)
// Time: O(n * (max-min)) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>res;
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=mn;i<=mx;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
              res.push_back(i);
            }
        }
        return res;
    }
};