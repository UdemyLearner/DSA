#include <bits/stdc++.h> 
/*
given:
	~ complete binar tree   => no change is stricture of the tree
	~ min heap              => N<L & N<R
	~ left < Right sub tree => L<R
	--------------------------------------
							=> LNR i.e Pre-Order
Algo->
	1. inorder
	2. used inorder values to create Pre-Order bst 
*/

void inorder(BinaryTreeNode* root,vector<int> &ans){
	if(root == NULL)
		return;
	if(root->left) inorder(root->left,ans);
	ans.push_back(root->data);
	if(root->right) inorder(root->right,ans);
}

void preOrderToBST(BinaryTreeNode* root, vector<int>&ans, int &i){
	if(!root) return;
	root->data = ans[i++];
	preOrderToBST(root->left, ans, i);
	preOrderToBST(root->right, ans, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	inorder(root,ans);
	int i=0;
	preOrderToBST(root,ans,i);
	return root;

}