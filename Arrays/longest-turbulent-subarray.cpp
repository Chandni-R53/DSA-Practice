// Problem: Longest Turbulent Subarray
// Link: https://leetcode.com/problems/longest-turbulent-subarray/description/
// Pattern: Kadane's Variant (track alternating sign changes)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1;
        int len=1;
        int prev=0;
        if(arr.size()==1)return 1;
        
        for(int i=0;i<arr.size()-1;i++){
            int curr;
            if(arr[i]<arr[i+1])curr=-1;
            else if(arr[i]>arr[i+1])curr=1;
            else curr=0;

            if(curr==0)len=1;
            else if(prev==0 || prev!=curr)len++;
            else len=2;

            prev=curr;
            ans=max(ans,len);
        }
        return ans;
    }
};