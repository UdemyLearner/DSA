//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    // int find_position(int in[],int &ele,int start,int end){
    //     for(int i=start;i<=end;i++){
    //         if(in[i]==ele)
    //         return i;
    //     }
    //     return -1;
    // }
    void creatMapping(int in[],map<int,int> &nodeToIndex,int n){
        for(int i=0;i<=n;i++){
             nodeToIndex[in[i]] = i;
        }
    }

    Node* solve(int in[],int pre[],int &index ,int start, int end,int n,map<int,int> &nodeToIndex){
        if(index >=n || start>end)
        return NULL ;
        
        int ele=pre[index++];
        Node * root=new Node(ele);
        int pos = -1;
        pos = nodeToIndex[ele];
        //int pos=-1;
        //pos=find_position(in,ele,start,end);
        
        root->left=solve(in,pre,index,start,pos-1,n,nodeToIndex);
        root->right=solve(in,pre,index,pos+1,end,n,nodeToIndex);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        //nodes to index mapping
        map<int,int> nodeToIndex;
        creatMapping(in,nodeToIndex,n);
        
        Node *ans=solve(in,pre,index,0,n-1,n,nodeToIndex);
        return ans;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends