// Problem: Minimum Number of Pushes to Type Word I
// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/
// Pattern: Greedy + Math (assign most frequent letters to fewest pushes)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int push=0;
        for(int i=0;i<n;i++){
            push+=(i/8)+1;
        }
        return push;
    }
};