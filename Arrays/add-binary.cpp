// Problem: Add Binary
// Link: https://leetcode.com/problems/add-binary/description/
// Pattern: String Simulation (bit-by-bit addition with carry)
// Time: O(max(n,m)) | Space: O(max(n,m))   [n = a.size(), m = b.size()]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int cary=0;
        int i=a.size()-1;
        int j=b.size()-1;
        while(i>=0||j>=0||cary){
           int sum=cary;
           if(i>=0){sum+=a[i]-'0';}
           if(j>=0){sum+=b[j]-'0';}
            res+=(sum%2)+'0';
            cary=sum/2;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};