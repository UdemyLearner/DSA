/*
TC->0(logn)
SC->O()    
*/
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

Node* minVal(Node* root){
    Node* t = root;
    while(t->left != NULL){
        t = t -> left;
    }
    return t;
}
Node* maxVal(Node* root){
    Node* t = root;
    while(t->right != NULL){
        t = t -> right;
    }
    return t;
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

Node* deleteBST(Node* root,int d){
    if(root == NULL)
        return root;
    if(root->data == d){  
        //0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
        //1 child
            //left Child
                if(root->left != NULL && root->right == NULL){
                    Node* t = root->left;
                    delete root;
                    return t;
                }
            //right child
                if(root->left == NULL && root->right != NULL){
                    Node* t = root->right;
                    delete root;
                    return t;
                }    
        //2 child
            //option1:left m sa max 
            //=>option2:right m sa min
            if(root->left != NULL && root->right != NULL){
                int mini = minVal(root->right)->data;
                root->data = mini;
                root -> right = deleteBST(root->right,mini);
                return root;
            }
            
    }else if(root->data > d)
    {
        root->left = deleteBST(root->left,d);
        return root;
    }else{
        root->right = deleteBST(root->right,d);
        return root;
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
    cout<<endl<<"Min Values is  :  "<<minVal(root)->data;
    cout<<endl<<"Max Values is  :  "<<maxVal(root)->data<<endl;
    root = deleteBST(root,90);
    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    return 0;
}
// 10 8 21 7 21 5 4 3 -1
// 50 20 70 10 30 90 110 -1