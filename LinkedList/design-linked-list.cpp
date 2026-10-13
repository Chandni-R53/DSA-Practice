// Problem: Design Linked List
// Link: https://leetcode.com/problems/design-linked-list/description/
// Pattern: Linked List (implementation — get, insert, delete)
// Time: O(n) per operation | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
    struct Node{
        int val;
        Node* next;
        Node(int x){
            val=x;
            next=nullptr;
        };
    };
    Node* head;
    MyLinkedList() {
        head=nullptr;
    }
    
    int get(int index) {
        if(index<0)return -1;
        Node* temp=head;
        for(int i=0;i<index && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL)return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
    }
    
    void addAtTail(int val) {
        Node* lastnode=new Node(val);
        if(head==NULL){
            head=lastnode;
        }
        else{
           Node* temp=head;
           while(temp->next!=NULL){
              temp=temp->next;
            }
            temp->next=lastnode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index<0)return;
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* temp=head;
        Node* newnode=new Node(val);
        for(int i=0;i<index-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL)return;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    
    void deleteAtIndex(int index) {
        if(index<0)return;
        if(head==NULL)return;
        if(index==0){
            head=head->next;
            return;
        }
        Node* temp=head;
        Node* prev=NULL;
        int count=0;
        while(temp!=NULL){
           count++;
           if(count-1==index){
              prev->next=prev->next->next;
              delete temp;
              break;
           }
           prev=temp;
           temp=temp->next;
        }
    }
};

int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);         // 1 -> 2 -> 3
    cout << obj->get(1) << endl;   // 2
    obj->deleteAtIndex(1);         // 1 -> 3
    cout << obj->get(1) << endl;   // 3
    return 0;
}