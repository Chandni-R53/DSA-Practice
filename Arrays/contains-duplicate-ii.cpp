// Problem: Contains Duplicate II
// Link: https://leetcode.com/problems/contains-duplicate-ii/description/
// Pattern: Sliding Window + HashSet (fixed size window of k)
// Time: O(n) | Space: O(k)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_set<int>s;
       int l=0,r=l;
       while(r<nums.size()){
        if(abs(l-r)>k){
            s.erase(nums[l]);
            l++;
        }
        if(s.find(nums[r])!=s.end())return true;
        s.insert(nums[r]);
        r++;
       }
       return false;
    }
};