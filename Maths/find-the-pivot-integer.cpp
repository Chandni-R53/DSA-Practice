// Problem: Find the Pivot Integer
// Link: https://leetcode.com/problems/find-the-pivot-integer/description/
// Pattern: Prefix Sum (total sum - left sum - current = right sum)
// Time: O(n) | Space: O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
        int left=0;
        for(int i=1;i<=n;i++)sum+=i;
        for(int i=1;i<=n;i++){
           int right=sum-left-i;
           if(left==right)return i;
           left+=i;
        }
        return -1;
    }
};