pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //find key
    BinaryTreeNode<int>* t = root;
    int pre = -1;
    int succ =-1;
    while(t->data !=key){
      if (t->data > key){
            succ = t->data;
            t = t->left;
      }else{
        pre = t ->data;
          t = t -> right;
      }
    }

    //pre and succ

        //pre : max value from that node
            BinaryTreeNode<int>* lt = t -> left;
            while(lt!=NULL){
                pre = lt->data;
                lt = lt->right;
            }
        //succ : min value from that node
                    BinaryTreeNode<int>* rt = t -> right;
                    while(rt!=NULL){
                        succ = rt->data;
                        rt = rt->left;
                    }
    pair<int,int> ans = make_pair(pre,succ);
    return ans;
}