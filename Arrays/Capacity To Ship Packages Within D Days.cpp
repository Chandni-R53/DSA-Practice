// Problem: Capacity To Ship Packages Within D Days
// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// Pattern: Binary Search on Answer (find the minimum ship capacity where days needed <= D)
// Time: O(n log(sum(weights))) | Space: O(1)

class Solution {
public:
    bool capacity(vector<int>& weights, int mid,int days){
        int curWeight=0;
        int day=1;
        for(int i=0;i<weights.size();i++){
           if(curWeight+weights[i]<=mid){
            curWeight+=weights[i];
           }
           else{
            day++;
            curWeight=weights[i];
           }
        }
        if(day<=days)return true;
        else return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mx=*max_element(weights.begin(),weights.end());
        int total=0;
        for(int i:weights){
            total+=i;
        }
        int ans=INT_MAX;
        int low=mx;
        int high=total;
        while(low<=high){
          int mid=low+(high-low)/2;
          bool val=capacity(weights,mid,days);
          if(val){
            ans=mid;
            high=mid-1;
          }
          else{
            low=mid+1;
          }
        }
        return ans;
    }
};