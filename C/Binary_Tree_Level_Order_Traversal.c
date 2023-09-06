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
        int lheight = height(root -> left) + 1;
        int rheight = height(root -> right) + 1;
        if(lheight > rheight){
            return lheight;
        }
        else{
            return rheight;
        }
    }
}

void findNumber(struct TreeNode* root, int **arr, int *col, int level, int depth){
    if(!root){
        return;
    }
    if(level == depth){
        arr[depth][(*col)++] = root -> val;
        return;
    }
    findNumber(root -> left, arr, col, level, depth+1);
    findNumber(root -> right, arr, col, level, depth+1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int level = height(root);
    *returnSize = level;
    int **arr = malloc(sizeof(int*) * level);
    *returnColumnSizes = malloc(sizeof(int) * level);
    int col = 0;
    for(int i = 0; i < level; i++){
        arr[i] = malloc(sizeof(int) * 1024);
        findNumber(root, arr, &col, i, 0);
        (*returnColumnSizes)[i] = col;
        col = 0;
    }
    return arr;
    
}
