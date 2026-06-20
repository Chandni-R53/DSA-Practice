// Problem: Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Pattern: Sliding Window (variable size)
// Time: O(n) | Space: O(1)


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int min_len = INT_MAX;
        int sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                int len = j - i + 1;
                min_len = min(min_len, len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(min_len==INT_MAX){
            return 0;
        }
        else{
            return min_len;
        }
    }
};