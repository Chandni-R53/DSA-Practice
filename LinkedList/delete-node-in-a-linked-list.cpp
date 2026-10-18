// Problem: Delete Node in a Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// Pattern: Linked List (copy next value, skip next node)
// Time: O(1) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        temp->val=temp->next->val;
        temp->next=temp->next->next;
    }
};

int main(){
    // 4 -> 5 -> 1 -> 9, delete node with val=5
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution s;
    s.deleteNode(head->next); // delete 5

    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->val << " "; // 4 1 9
        temp = temp->next;
    }
    return 0;
}