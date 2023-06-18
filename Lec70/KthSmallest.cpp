int solve(TreeNode* root,int &i,int k){
        //base case
        if(root == NULL){
            return -1;
        }
        //L
            int l = solve(root->left,i,k);
            if(l != -1)
                return l;
        //N
            i++;
            if(i==k)
                return root->val;
        //R
        return solve(root->right,i,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans = solve(root,i,k);
        return ans;
    }