// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/description/
// Pattern: Binary Search on Answer (find the minimum speed k where total hours <= h)
// Time: O(n log(max(piles))) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long speed(vector<int>& piles,int mid){
            long long val=0;
            for(int i=0;i<piles.size();i++){
               val+=ceil((1LL*piles[i]+mid-1)/mid);
            }
            return val;
        }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        int low=1;
        int high=mx;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long k=speed(piles,mid);
            if(k<=h){
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