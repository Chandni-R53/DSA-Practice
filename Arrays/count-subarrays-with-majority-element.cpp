// Problem: Count Subarrays With Majority Element I
// Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/
// Pattern: Brute Force (nested loop, subarray enumeration)
// Time: O(n²) | Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int targetCount=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                   targetCount++;
                }
                int len=j-i+1;
                if(2*targetCount>len){
                    count++;
                }
            }
        }
        return count;
    }
};