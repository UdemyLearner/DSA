struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Optimes solution in terms of space
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (root->val < p->val && root->val < q->val)
            root = root->right;
        else if (root->val > p->val && root->val > q->val)
            root = root->left;
        else
            return root;
    }
    /*
    if(root==NULL){
        return NULL;
    }
    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right,p,q);
    }
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
    */
    return root;
}