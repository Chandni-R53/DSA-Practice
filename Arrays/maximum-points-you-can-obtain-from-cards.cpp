// Problem: Maximum Points You Can Obtain from Cards
// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// Pattern: Sliding Window (shrinking left, growing right)
// Time: O(k) | Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        maxSum=lsum;
        int j=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];
            maxSum=max(maxSum,lsum+rsum);
            j--;
        }
        return maxSum;
    }
};