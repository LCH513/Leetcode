/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkDepth(struct TreeNode* root,int depth){
    int count_L = 0;
    int count_R = 0;
    if(!root){
        return depth;
    }
    //find the left side
    count_L = checkDepth(root -> left, depth)+1;
    
    //find the right side
    count_R = checkDepth(root -> right, depth)+1;
    return ((count_L > count_R)?count_L:count_R);
}


int maxDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    return ((checkDepth(root -> left,1)>checkDepth(root -> right,1))?checkDepth(root -> left,1):checkDepth(root -> right,1));
}
