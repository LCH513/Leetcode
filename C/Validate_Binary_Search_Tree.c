/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getNodeCount(struct TreeNode* root){
    if(!root){
        return 0;
    }
    return getNodeCount(root -> left) + getNodeCount(root -> right) + 1;
}

void traversal(struct TreeNode* root, int *list, int *pos){
    if(root -> left != NULL){
        traversal(root -> left, list, pos);
    }
    list[(*pos)++] = root -> val;
    if(root -> right != NULL){
        traversal(root -> right, list, pos);
    }
    return;
}

bool isValidBST(struct TreeNode* root){
    if(!root){
        return true;
    }
    int count = getNodeCount(root);
    int *list = malloc(sizeof(int) * count);
    int pos = 0;
    traversal(root, list, &pos);
    for(int i = 1; i < count; i++){
        if(list[i-1] >= list[i]){
            return false;
        }
    }
    return true;
    
}
