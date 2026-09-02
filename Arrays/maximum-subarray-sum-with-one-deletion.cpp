// Problem: Maximum Subarray Sum with One Deletion
// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
// Pattern: Kadane's Variant (two states — with and without deletion)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0];
        int noDel=arr[0];
        int oneDel=INT_MIN;
        for(int i=1;i<arr.size();i++){
           int prevNoDel=noDel;
           int prevOneDel=oneDel;
           noDel=max(arr[i],noDel+arr[i]);

           int val;
           if(prevOneDel==INT_MIN)val=arr[i];
           else val=prevOneDel+arr[i];

           oneDel=max(val,prevNoDel);
           ans=max(ans,max(noDel,oneDel));
        }
        
        return ans;
    }
};