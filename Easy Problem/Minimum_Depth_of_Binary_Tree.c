int minDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }
    if(root -> left == NULL){
        return 1 + minDepth(root -> right); 
    }
    if(root -> right == NULL){
        return 1+ minDepth(root -> left);
    }
    int left_depth = 1+minDepth(root -> left);
    int right_depth = 1+minDepth(root -> right);
    
    return (left_depth>right_depth)?right_depth:left_depth;
}
