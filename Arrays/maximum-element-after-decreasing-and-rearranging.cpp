// Problem: Maximum Element After Decreasing and Rearranging
// Link: https://leetcode.com/problems/maximum-element-after-decrementing-and-rearranging/
// Pattern: Greedy + Sorting
// Time: O(n log n) | Space: O(1) (excluding sorting space)

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=ans+1)ans++;
        }
        
        return ans;
    }
};