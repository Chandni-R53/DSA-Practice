// Problem: Best Time to Buy and Sell Stock II
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
// Pattern: Greedy (accumulate every upward price difference)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
           if(prices[i]>prices[i-1]){
            profit+=prices[i]-prices[i-1];
           }
        }
        return profit;
    }
};