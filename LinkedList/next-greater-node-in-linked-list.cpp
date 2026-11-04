// Problem: Next Greater Node In Linked List
// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/description/
// Pattern: Linked List + Brute Force (nested scan for next greater)
// Time: O(n²) | Space: O(1)   [excluding output vector]

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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* curr;
        bool greater;
        vector<int> ans;
        while(temp!=NULL){
            greater=false;
            curr=temp->next;
            while(curr!=NULL){
              if(temp->val < curr->val){
                ans.push_back(curr->val);
                greater=true;
                break;
              }
              else{
                curr=curr->next;
              }
            }
            if(!greater){
              ans.push_back(0);
            }
            temp=temp->next;
        }
       
        return ans;
    }
};

int main(){
    // 2 -> 1 -> 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    Solution s;
    vector<int> res = s.nextLargerNodes(head);
    for(int x : res) cout << x << " "; // 5 5 0
    return 0;
}