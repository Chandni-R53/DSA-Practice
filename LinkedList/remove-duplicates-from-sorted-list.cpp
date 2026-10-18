// Problem: Remove Duplicates from Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Pattern: Linked List (two pointer, skip duplicate nodes)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
          if(curr->val==prev->val){
            prev->next=curr->next;
            curr=curr->next;
          }
          else{
            prev=curr;
            curr=curr->next;
          }
        }
        return head;
    }
};

int main(){
    // 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution s;
    ListNode* res = s.deleteDuplicates(head);
    while(res != NULL){
        cout << res->val << " "; // 1 2 3
        res = res->next;
    }
    return 0;
}