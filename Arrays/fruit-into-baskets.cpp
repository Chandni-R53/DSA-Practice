// Problem: Fruit Into Baskets
// Link: https://leetcode.com/problems/fruit-into-baskets/description/
// Pattern: Sliding Window + HashMap (at most 2 distinct elements)
// Time: O(n log n) | Space: O(1)   [map ops are O(log n), at most 3 keys ever]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        int l=0,r=0;
        map<int,int>m;
        while(r<fruits.size()){
            m[fruits[r]]++;
            if(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)m.erase(fruits[l]);
                l++;
            }
            else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};