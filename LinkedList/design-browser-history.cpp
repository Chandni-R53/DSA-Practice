// Problem: Design Browser History
// Link: https://leetcode.com/problems/design-browser-history/description/
// Pattern: Doubly Linked List (prev/next navigation)
// Time: O(n) back/forward | O(1) visit | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    struct Node{
        string val;
        Node* next;
        Node* prev;
        Node(string x){
            val=x;
            next=nullptr;
            prev=nullptr;
        };
    };
    Node* curr;
    BrowserHistory(string homepage) {
         curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps>0 && curr->prev!=NULL){
            curr=curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        int move=0;
        while(move!=steps && curr->next!=NULL){
           curr=curr->next;
           move++;
        }
        return curr->val;
    }
};

int main(){
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    cout << obj->back(1) << endl;    // facebook.com
    cout << obj->back(1) << endl;    // google.com
    cout << obj->forward(1) << endl; // facebook.com
    obj->visit("linkedin.com");
    cout << obj->forward(2) << endl; // linkedin.com
    cout << obj->back(2) << endl;    // google.com
    cout << obj->back(7) << endl;    // leetcode.com
    return 0;
}