#include <iostream>
#include<queue>
using namespace std;
//Inorder of bst is alredy sorted 
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(Node* &root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}
void preorder(Node* &root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* &root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
void insertintoBST(Node *&root, int d)
{
    // Base Case
    if (root == NULL)
    {
        root = new Node(d);
        return;
    }

    if (d > root->data)
    {
        // right part insert
        insertintoBST(root->right, d);
    }
    else
    {
        // insert into left part
        insertintoBST(root->left, d);
    }
}

void takeinput(Node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertintoBST(root, d);
        cin >> d;
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    cout << "Enter data to creat BST" << endl;
    takeinput(root);
    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    cout<<"Printing inOrder"<<endl;
    inorder(root);
    cout<<endl<<"Printing preOrder"<<endl;
    preorder(root);
    cout<<endl<<"Printing postOrder"<<endl;
    postorder(root);
    return 0;
}
// 10 8 21 7 21 5 4 3 -1
// 10 8 21 7 27 5 4 3 22 6 -1