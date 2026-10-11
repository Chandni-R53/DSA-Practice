// Problem: Convert Binary Number in a Linked List to Integer
// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
// Pattern: Linked List Traversal + Bit Manipulation (shift and add)
// Time: O(n) | Space: O(1)

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
    int getDecimalValue(ListNode* head) {
        int prev=0;
        ListNode* temp=head;
        while(temp!=NULL){
          int curr=temp->val;
          prev=prev*2+curr;
          temp=temp->next;
        }
        return prev;
    }
};