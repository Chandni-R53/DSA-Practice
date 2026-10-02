// Problem: Kth Smallest Element in a Sorted Matrix
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
// Pattern: Binary Search on Answer + Staircase Count
// Time: O(n log(max-min)) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int elementCount(vector<vector<int>>& matrix, int mid, int n){
        int count=0;
        int row=0,col=n-1;
        while(row<n && col>=0){
            if(matrix[row][col]<=mid){
                count+=col+1;
                row++;
            }
            else{ col--;}
            
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=elementCount(matrix,mid,n);
            if(count>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};