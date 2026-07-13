// Problem: Sequential Digits
// Link: https://leetcode.com/problems/sequential-digits/description/
// Pattern: BFS (digit generation, level order expansion)
// Time: O(1) | Space: O(1)   [at most 36 sequential digit numbers exist]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       queue<int>q;
       vector<int>ans;
       for(int i=1;i<9;i++){
        q.push(i);
       }
       while(!q.empty()){
        int temp=q.front();
        q.pop();
        if(temp>=low && temp<=high){
            ans.push_back(temp);
        }
        int ld=temp%10;
        if(ld+1<=9){
            int num=temp*10+ld+1;
            q.push(num);
        }
     }
        
       return ans;
    }
};