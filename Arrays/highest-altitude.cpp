// Problem: Find the Highest Altitude
// Link: https://leetcode.com/problems/find-the-highest-altitude/description/
// Pattern: Prefix Sum, single pass
// Time: O(n) | Space: O(n)

#include <vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>v;
        v.push_back(0);
        int alt=0;
        for(int i=0;i<n;i++){
            v.push_back(gain[i]+v[i]);
            alt=max(alt,v[i+1]);
        }
        return alt;
    }
};