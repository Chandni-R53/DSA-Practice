// Problem: Remove Element
// Link: https://leetcode.com/problems/remove-element/description/
// Pattern: Two Pointer (slow-fast, in-place overwrite)
// Time: O(n) | Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int el=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[el]=nums[i];
                el++;
            }
        }
        return el;

    }
};