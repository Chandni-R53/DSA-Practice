// Problem: First Bad Version
// Link: https://leetcode.com/problems/first-bad-version/description/
// Pattern: Binary Search (find leftmost true condition)
// Time: O(log n) | Space: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int res;
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool val=isBadVersion(mid);
            if(val){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};