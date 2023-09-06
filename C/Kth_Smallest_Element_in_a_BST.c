/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, int *arr, int* count){
    if(root == NULL){
        return;
    }
    inorder(root -> left, arr, count);
    arr[(*count)++] = root -> val;
    inorder(root -> right, arr, count);
}
    
    
int kthSmallest(struct TreeNode* root, int k){
    int *arr = malloc(sizeof(int) * 10000);
    int count = 0;
    inorder(root, arr, &count);
    return arr[k-1];
}
