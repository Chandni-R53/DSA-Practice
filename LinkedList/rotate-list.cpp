// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/description/
// Pattern: Linked List (find tail, make circular, break at new head)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        int len = 1;
        while (temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        ListNode* tail = temp;
        k = k % len;
        if (k == 0) return head;

        int steps = len - k;
        temp = head;
        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
    }
};

int main(){
    // 1 -> 2 -> 3 -> 4 -> 5, k=2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode* res = s.rotateRight(head, 2);
    while(res != NULL){
        cout << res->val << " "; // 4 5 1 2 3
        res = res->next;
    }
    return 0;
}