// Problem: Number of Unique XOR Triplets II
// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
// Pattern: Brute Force + HashSet (enumerate all pairs then triplets)
// Time: O(n³) | Space: O(n²)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>xorPair;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                xorPair.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>ans;
        for(int i:xorPair){
            for(int &j:nums){
                ans.insert(i^j);
            }
        }
        return ans.size();
    }
};