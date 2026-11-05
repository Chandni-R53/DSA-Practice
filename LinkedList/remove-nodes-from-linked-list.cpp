// Problem: Remove Nodes From Linked List
// Link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/
// Pattern: Linked List (reverse, keep running max, reverse back)
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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front;
        while(curr!=NULL){
          front=curr->next;
          curr->next=prev;
          prev=curr;
          curr=front;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp=reverse(head);
        ListNode* prev=temp;
        ListNode* curr=temp->next;
        while(curr!=NULL){
            if(curr->val < prev->val){
                prev->next=curr->next;
            }
            else{ prev=curr; }
            curr=curr->next;
        }
        head=reverse(temp);
        return head;
    }
};

int main(){
    // 5 -> 2 -> 13 -> 3 -> 8
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution s;
    ListNode* res = s.removeNodes(head);
    while(res != NULL){
        cout << res->val << " "; // 13 8
        res = res->next;
    }
    return 0;
}