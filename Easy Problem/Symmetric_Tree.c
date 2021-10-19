/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//using recursion

bool checkSymmetric(struct TreeNode* L, struct TreeNode* R){
    if(!L && !R){
        return true;
    }
    
    if(!L || !R){
        return false;
    }
    if(L -> val == R -> val){
        return checkSymmetric(L -> left, R->right) && checkSymmetric(L -> right, R -> left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if(!root){
        return true;
    }
    
    return checkSymmetric(root -> left, root -> right);
}
