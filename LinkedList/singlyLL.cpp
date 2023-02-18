#include <iostream>
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
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insterAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node*temp = head;
        head= head -> next;
        temp -> next =NULL;
        delete temp;
    }
    else
    {
        Node *curr=head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt<pos)
        {
            prev = curr;
            curr=curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next =  NULL;
        delete curr;

    }
}

int main(int argc, char const *argv[])
{
    // Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout<< node1->nxt << endl;
    // Node *head = node1;

    Node *head = new Node(10);
    Node *tail = head;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);
    insertAtHead(head, 12);
    print(head);
    /*
        10
        10 15
        12 10 15
    */
    // insterAtPosition(head,tail,3,222);
    // print(head);
    // insterAtPosition(head,tail,1,2222);
    // print(head);
    insterAtPosition(head, tail, 5, 22);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(4,head);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    return 0;
}
