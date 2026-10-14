// Problem: Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/description/
// Pattern: Floyd's Cycle Detection (slow-fast pointers)
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};

int main(){
    // 3 -> 2 -> 0 -> -4 -> (back to 2)
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle

    Solution s;
    cout << (s.hasCycle(head) ? "true" : "false") << endl; // true
    return 0;
}