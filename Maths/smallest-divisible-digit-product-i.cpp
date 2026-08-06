// Problem: Smallest Divisible Digit Product I
// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Pattern: Brute Force (linear search + digit product)
// Time: O(n * d) | Space: O(1)   [d = number of digits, n = steps to answer]

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int num=n;
            int product=1;
            while(num>0){
              int digit=num%10;
              product*=digit;
              num/=10;
            }
            if(product%t==0)return n;
            else n+=1;
        }
        
    }
};