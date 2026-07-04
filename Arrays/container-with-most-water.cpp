// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/description/
// Pattern: Two Pointer (converging, greedy — move shorter wall)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            water=max(water,h*w);
            height[i]<height[j]?i++:j--;
        }
        return water;
    }
};