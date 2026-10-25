// Problem: Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
// Pattern: Linked List (dummy node + two pointer merge)
// Time: O(n+m) | Space: O(1)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else if(temp1->val > temp2->val){
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
            else{
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1==NULL && temp2!=NULL){
          while(temp2!=NULL){
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
          }
        }
        if(temp1!=NULL && temp2==NULL){
          while(temp1!=NULL){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
          }
        }
        return dummy->next;
    }
};

int main(){
    // 1 -> 2 -> 4  and  1 -> 3 -> 4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* res = s.mergeTwoLists(l1, l2);
    while(res != NULL){
        cout << res->val << " "; // 1 1 2 3 4 4
        res = res->next;
    }
    return 0;
}