// Problem: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/description/
// Pattern: Linked List + Two Pointer (store values, converging check)
// Time: O(n) | Space: O(n)   [vector stores all node values]

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        vector<int>v;
        ListNode* curr=head;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]!=v[j])return false;
            i++;
            j--;
        }
        return true;
    }
};

int main(){
    // 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    cout << (s.isPalindrome(head) ? "true" : "false") << endl; // true
    return 0;
}