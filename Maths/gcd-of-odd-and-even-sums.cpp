// Problem: GCD of Odd and Even Sums
// Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
// Pattern: Math (arithmetic series + GCD)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=1;
        int even=2;
        long long oddSum=0;
        long long evenSum=0;
        while(n>0){
             oddSum+=odd;
             odd+=2;
             evenSum+=even;
             even+=2;
             n--;
        }
        return __gcd(oddSum,evenSum);
    }
};