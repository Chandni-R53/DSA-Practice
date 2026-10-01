// Problem: Minimum Number of Days to Make m Bouquets
// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Pattern: Binary Search on Answer (find the minimum day where at least m bouquets of k adjacent flowers can be made)
// Time: O(n log(max(bloomDay) - min(bloomDay))) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k,int mid){
        int count=0;
        int bouqets=0;
        for(int i=0;i<bloomDay.size();i++){
          if(bloomDay[i]<=mid){
            count++;
          }
          else{
            bouqets+=count/k;
            count=0;
          }
        }
        bouqets+=count/k;
        if(bouqets>=m)return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<1LL*m*k)return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
          int mid=low+(high-low)/2;
          bool val=possible(bloomDay,m,k,mid);
          if(val){
            high=mid-1;
          }
          else{
            low=mid+1;
          }
        }
        return low;
    }
};