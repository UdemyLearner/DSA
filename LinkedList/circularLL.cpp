#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory freed for the node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // element is present in the list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // elemnet id found
        // current is at element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        // non-empty
        // assuming value is present in the list
        //curr is the node which is to deleted
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //for 1 node LL
        if(curr == prev){
            tail==NULL;
        }
        
        //>=2 Node LL
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 9, 10);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 6);
    print(tail);
    deleteNode(tail, 9);
    print(tail);
    deleteNode(tail, 10);
    deleteNode(tail, 4);
    deleteNode(tail, 5);
    //deleteNode(tail, 7);
    print(tail);

    return 0;
}