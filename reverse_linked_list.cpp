#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head=NULL;
    }

    /*Itterative method*/
    
    /*void reverse(){
        Node* current=head;
        Node *prev=NULL, *next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }*/
    
    /*Recursive method*/
    Node* reverse(Node* head){
        if(head==NULL || head->next==NULL)
            return head;
        
        Node* rest = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }

    void print(){
        struct Node* temp = head;
        while(temp!=NULL){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }

    void push(int data){
        Node* temp =new Node(data);
        temp->next=head;
        head=temp;
    }
};

int main(){
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(15);
    ll.push(85);
    cout<<"Linked list:\n";
    ll.print();
    ll.reverse();
    cout<<"Reverse Linked List:\n";
    ll.print();
    return 0;
}
