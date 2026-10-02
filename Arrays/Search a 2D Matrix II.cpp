// Problem: Search a 2D Matrix II
// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Pattern: Binary Search (row filter + binary search per row)
// Time: O(n log m) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int i, int m, int target){
        int low=0,high=m-1;
        while(low<=high){
          int mid=low+(high-low)/2;
          if(matrix[i][mid]==target)return true;
          else if(matrix[i][mid]<target)low=mid+1;
          else high=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
              if(binarySearch(matrix,i,m,target))return true;
            }
        }
        return false;
    }
};