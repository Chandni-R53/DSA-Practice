// Problem: Maximum Average Subarray I
// Link: https://leetcode.com/problems/maximum-average-subarray-i/description/
// Pattern: Sliding Window (fixed size k)
// Time: O(n) | Space: O(1)


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double avg=(double)sum/k;
       for(int i=k;i<nums.size();i++){
        sum+=nums[i];
        sum-=nums[i-k];
        avg=max(avg,(double)sum/k);
       }
        return avg;
    }
};