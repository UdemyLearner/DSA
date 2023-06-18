bool isBST(TreeNode* root,long min ,long max){
    if(root==NULL)
        return true;
    
    if(root->val > min && root->val <max){
        bool left = isBST(root->left,min,root->val);
        bool right = isBST(root->right,root->val,max);
        return left && right;
    }
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,LONG_MIN,INT.MAX);
}