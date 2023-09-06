/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int height(struct TreeNode* root){
    if(!root){
        return 0;
    }
    else{
        int lheight = height(root -> left)+1;
        int rheight = height(root -> right)+1;
        if(lheight > rheight){
            return lheight;
        }    
        else{
            return rheight;
        }
    }
}

void findNumber(struct TreeNode* root, int** ans, int* col, int level, int depth){
    if(!root){
        return;
    }
    if(level == depth){
        ans[level][(*col)++] = root -> val;
        return;
    }
    if(level % 2 == 0){
        findNumber(root -> left, ans, col, level, depth+1);
        findNumber(root -> right, ans, col, level, depth+1);
    }
    else{
        findNumber(root -> right, ans, col, level, depth+1);
        findNumber(root -> left, ans, col, level, depth+1);
    }
}


int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int level = height(root);
    int** ans = malloc(sizeof(int*) * level);
    *returnColumnSizes = malloc(sizeof(int) * level);
    int col = 0;
    for(int i = 0; i < level; i++){
        ans[i] = malloc(sizeof(int) * 1024);
        findNumber(root, ans, &col, i, 0);
        (*returnColumnSizes)[i] = col;
        col = 0;
    }
    *returnSize = level;
    return ans;
}
