// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/description/
// Pattern: Linked List (dummy node + digit-by-digit addition with carry)
// Time: O(max(n,m)) | Space: O(max(n,m))

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
           int sum=carry;
           if(temp1)sum+=temp1->val;
           if(temp2)sum+=temp2->val;
           ListNode* newNode=new ListNode(sum%10);
           carry=sum/10;
           curr->next=newNode;
           curr=curr->next;
           if(temp1)temp1=temp1->next;
           if(temp2)temp2=temp2->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
        return dummy->next;   
    }
};

int main(){
    // 342 + 465 = 807
    // l1: 2->4->3, l2: 5->6->4
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while(res != NULL){
        cout << res->val << " "; // 7 0 8
        res = res->next;
    }
    return 0;
}