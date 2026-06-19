// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Pattern: Single pass, running minimum
// Time: O(n) | Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
           buy=min(buy,prices[i]);
           int sell=prices[i]-buy;
           profit=max(profit,sell);
        }
        return profit;
    }
};