// Problem: Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/description/
// Pattern: Floyd's Cycle Detection (array as linked list)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,j=0;
        while(true){
            i=nums[i];
            j=nums[j];
            j=nums[j];
            if(i==j){
                i=0;
                while(i!=j){
                    i=nums[i];
                    j=nums[j];
                }
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl; // 2
    return 0;
}