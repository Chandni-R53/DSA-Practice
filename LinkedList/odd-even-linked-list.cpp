// Problem: Odd Even Linked List
// Link: https://leetcode.com/problems/odd-even-linked-list/description/
// Pattern: Linked List (two pointer, separate odd/even then merge)
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* curr=head->next;
        ListNode* prev=head;
        int idx=2;
        while(curr!=NULL){
            if(idx%2!=0){
              prev->next=curr;
              prev=curr;
            }
            else{
              temp->next=curr;
              temp=curr;
            }
            idx++;
            curr=curr->next;
        }
        temp->next=NULL;
        prev->next=dummy->next;
        return head;
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
    ListNode* res = s.oddEvenList(head);
    while(res != NULL){
        cout << res->val << " "; // 1 3 5 2 4
        res = res->next;
    }
    return 0;
}