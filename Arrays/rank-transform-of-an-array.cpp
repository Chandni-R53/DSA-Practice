// Problem: Rank Transform of an Array
// Link: https://leetcode.com/problems/rank-transform-of-an-array/description/
// Pattern: Sorting + HashMap (value to rank mapping)
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
        int rank=0;
        for(int i:v){
            if(m.find(i)==m.end()){
                rank++;
                m[i]=rank;
            }
            else{
                m[i]=rank;
            }
        }
        for(auto &i:arr){
           i=m[i];
        }
        return arr;
    }
};