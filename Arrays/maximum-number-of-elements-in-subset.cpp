// Problem: Find the Maximum Number of Elements in Subset
// Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/
// Pattern: HashMap + Greedy (power chain traversal)
// Time: O(n log log M) | Space: O(n)   [M = max element, chain length is log log M]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums)mp[x]++;
        int ans=1;
        
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(x==1){
                if(mp[x]%2!=0)ans=max(ans,mp[x]);
                else ans=max(ans,mp[x]-1);
            }
            else{
                int ct=0;
                if(mp[x]>=2){
                    long long curr=x;
                    while(curr<=INT_MAX && mp.find((int)curr)!=mp.end()){
                        if(mp[(int)curr]==1){
                            ct++;
                            break;
                        }
                        ct++;
                        if(curr>LLONG_MAX/curr)break;
                        curr*=curr;
                    }
                }
                ans=max(ans,ct*2-1);
            }
        }

        return ans;
    }
};