// Problem: Concatenate Non-Zero Digits and Multiply by Sum I
// Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/
// Pattern: Math + String Manipulation (digit extraction, reverse)
// Time: O(d) | Space: O(d)   [d = number of digits in n]


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long sumAndMultiply(int n) {
        string x="";
        long long sum=0;
        while(n>0){
            int digit=n%10;
            if(digit>0)x+=digit+'0';
            n/=10;
        }
        if(x.empty())return 0;
        reverse(x.begin(),x.end());
        for(char c:x){
           sum+=c-'0';
        }
        return sum*stoll(x);
    }
};