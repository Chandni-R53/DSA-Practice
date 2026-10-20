// Problem: Linked List Cycle II
// Link: https://leetcode.com/problems/linked-list-cycle-ii/description/
// Pattern: Floyd's Cycle Detection (find entry point of cycle)
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
              slow=head;
              while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
              }
              return slow;
            }
        }
        return NULL;
    }
};

int main(){
    // 3 -> 2 -> 0 -> -4 -> (back to 2)
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle at node 2

    Solution s;
    ListNode* res = s.detectCycle(head);
    cout << (res ? to_string(res->val) : "null") << endl; // 2
    return 0;
}