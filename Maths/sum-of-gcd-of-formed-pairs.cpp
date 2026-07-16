// Problem: Sum of GCD of Formed Pairs
// Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/
// Pattern: Prefix GCD + Sorting + Two Pointer
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcd;
        int mx=nums[0];
        for(int i:nums){
            mx=max(mx,i);
            int el=__gcd(i,mx);
            prefixGcd.push_back(el);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        
        long long sum=0;
        int i=0;
        int j=prefixGcd.size()-1;
        while(i<j){
            sum+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};