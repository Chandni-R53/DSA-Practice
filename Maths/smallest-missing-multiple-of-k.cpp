// Problem: Smallest Missing Multiple of K
// Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/description/
// Pattern: Brute Force + Linear Search (iterate multiples, check existence)
// Time: O(n * m) | Space: O(1)   [m = number of multiples checked]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=2;
        int n=k;
        while(true){
            auto it=find(nums.begin(),nums.end(),n);
            if(it==nums.end())return n;
            n=k*i;
            i++;
        }
        return 0;
    }
};