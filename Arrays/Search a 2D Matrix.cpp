// Problem: Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/description/
// Pattern: Binary Search on a flattened 2D matrix (treat the matrix as one sorted array, map index to row/col)
// Time: O(log(m*n)) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); //rows
        int m=matrix[0].size(); //col
        
        int low=0;
        int high=(m*n)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};