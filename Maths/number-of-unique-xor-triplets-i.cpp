// Problem: Number of Unique XOR Triplets I
// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// Pattern: Math (bit manipulation, power of 2)
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==2)return n;
        int ans=1;
        while(ans<=n){
            ans*=2;
        }
        return ans;
    }
};