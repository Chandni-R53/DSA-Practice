// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Pattern: Two Pointer (slow-fast, in-place)
// Time: O(n) | Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count=1;
       int i=0;
       int j=1;
       while(j<nums.size()){
        if(nums[j]==nums[j-1]){
            j++;
            continue;
        }
        nums[i+1]=nums[j];
        i++;
        count++;
        j++;
       }
       
       return count;
    }
};