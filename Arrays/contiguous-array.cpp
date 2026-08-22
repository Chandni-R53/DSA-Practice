// Problem: Contiguous Array
// Link: https://leetcode.com/problems/contiguous-array/description/
// Pattern: Prefix Sum + HashMap (balance tracking, first occurrence index)
// Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0;
        m[0]=-1;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)sum--;
            else sum++;
             
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
            if(m.find(sum)!=m.end()){
                maxlen=max(maxlen,i-m[sum]);
            }
        }
        return maxlen;
    }
};