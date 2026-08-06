// Problem: Fruits Into Baskets II
// Link: https://leetcode.com/problems/fruits-into-baskets-ii/description/
// Pattern: Brute Force (greedy matching, linear search)
// Time: O(n²) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int placed=0;
        vector<bool>used(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && used[j]==false){
                    placed++;
                    used[j]=true;
                    break;
                }
            }
        }
        return n-placed;
    }
};