// Problem: Reverse Linked List II
// Link: https://leetcode.com/problems/reverse-linked-list-ii/description/
// Pattern: Linked List + Stack (collect range values, overwrite in reverse)
// Time: O(n) | Space: O(n)   [stack stores right-left+1 elements]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        stack<int>st;
        int cnt=1;
        while(cnt<=right && temp!=NULL){
            if(cnt==left){
                while(cnt<=right && temp!=NULL){
                  st.push(temp->val);
                  temp=temp->next;
                  cnt++;
                }
                break;
            }
            else{
                cnt++;
                temp=temp->next;
            }
        }
        int move=1;
        temp=head;
        while(move<=right && temp!=NULL){
            if(move==left){
              while(move<=right && temp!=NULL){
                temp->val=st.top();
                st.pop();
                temp=temp->next;
                move++;
              }
            }
            else{
               move++;
               temp=temp->next;
            }
        }
        return head;
    }
};

int main(){
    // 1 -> 2 -> 3 -> 4 -> 5, left=2, right=4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* res = s.reverseBetween(head, 2, 4);
    while(res != NULL){
        cout << res->val << " "; // 1 4 3 2 5
        res = res->next;
    }
    return 0;
}