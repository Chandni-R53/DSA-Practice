// Problem: Maximum Number of Ice Cream Bars
// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21
// Pattern: Greedy + Counting Sort
// Time: O(n + m) | Space: O(m)   [m = max element in costs]

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       int mx=*max_element(costs.begin(),costs.end());
       vector<int>v(mx+1,0);
       for(int i:costs){
        v[i]++;
       }
       int count=0;
       for(int i=1;i<=mx;i++){
        while(v[i]>0&&coins>=i){
            count++;
            coins-=i;
            v[i]--;
        }
       }
       return count;

    }
};