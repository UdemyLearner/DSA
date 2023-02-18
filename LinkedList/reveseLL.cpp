#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next !=NULL){
            delete next;
            this -> next =NULL;
        }
        cout<<"memory freed for "<<value<<endl;
    }
};
Node * reverseLL(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *fwd = NULL;

    while(curr!=NULL){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}
int main()
{
    
    return 0;
}