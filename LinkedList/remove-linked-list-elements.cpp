// Problem: Remove Linked List Elements
// Link: https://leetcode.com/problems/remove-linked-list-elements/description/
// Pattern: Linked List (dummy node + two pointer, skip target nodes)
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=head;
        
        while(curr!=NULL){
            if(curr->val==val){
               prev->next=curr->next;
               curr=curr->next;
            }
            else{
               prev=curr;
               curr=curr->next;
            }
        }
        return dummy.next;
    }
};

int main(){
    // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, remove 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution s;
    ListNode* res = s.removeElements(head, 6);
    while(res != NULL){
        cout << res->val << " "; // 1 2 3 4 5
        res = res->next;
    }
    return 0;
}