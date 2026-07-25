// Problem: Maximum Product of Two Digits
// Link: https://leetcode.com/problems/maximum-product-of-two-digits/description/
// Pattern: Math + Brute Force (digit extraction, pair enumeration)
// Time: O(d²) | Space: O(d)   [d = number of digits in n, max 9]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(int n) {
        int ans=0;
        vector<int>v;
        while(n>0){
            int digit=n%10;
            v.push_back(digit);
            n/=10;
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                ans=max(ans,v[i]*v[j]);
            }
        }
        return ans;
    }
};