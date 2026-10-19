// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/description/
// Pattern: Linked List (iterative three-pointer reversal)
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* front;
        while(curr!=NULL){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
};

int main(){
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* res = s.reverseList(head);
    while(res != NULL){
        cout << res->val << " "; // 5 4 3 2 1
        res = res->next;
    }
    return 0;
}