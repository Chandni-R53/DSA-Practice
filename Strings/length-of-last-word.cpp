// Problem: Length of Last Word
// Link: https://leetcode.com/problems/length-of-last-word/
// Pattern: String Traversal (reverse scan)
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int i=s.size()-1;
        while(i>=0&&s[i]==' '){
            i--;
        }
        while(i>=0&&s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};