// Problem: Find Greatest Common Divisor of Array
// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
// Pattern: Math (GCD of min and max)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int ans=__gcd(mn,mx);
        return ans;
    }
};