// Problem: Maximum Number of Vowels in a Substring of Given Length
// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
// Pattern: Sliding Window (fixed size k)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int vowel=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')vowel++;
        }
        int ans=vowel;
        for(int i=k;i<s.size();i++){
          if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')vowel++;
          if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')vowel--;
          ans=max(ans,vowel);
        }
        return ans;
    }
};