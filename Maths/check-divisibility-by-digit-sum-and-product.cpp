// Problem: Check Divisibility by Digit Sum and Product
// Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/
// Pattern: Math (digit extraction, sum and product)
// Time: O(d) | Space: O(1)   [d = number of digits in n]

class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        long long sum=0, prod=1;
        while(n>0){
           int digit=n%10;
           sum+=digit;
           prod*=digit;
           n/=10;
        }
        long long newSum=sum+prod;
        if(num%newSum==0)return true;
        else return false;
    }
};