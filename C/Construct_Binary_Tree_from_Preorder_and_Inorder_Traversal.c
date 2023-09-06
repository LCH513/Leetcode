/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* addTree(int* preorder, int* inorder, int size){
    if(size == 0){
        return NULL;
    }
    int i = 0;
    struct TreeNode* tree = malloc(sizeof(struct TreeNode));
    tree -> val = preorder[0];
    while(inorder[i] != preorder[0]){
        i++;
    }
    tree -> left = addTree(preorder+1, inorder, i);
    tree -> right = addTree(preorder+1+i, inorder+ i + 1, size - i - 1 );
    return tree;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* tree = malloc(sizeof(struct TreeNode));
    if(preorderSize == 1){
        tree -> val = preorder[0];
        tree -> left = NULL;
        tree -> right = NULL;
        return tree;
    }
    else{
        return addTree(preorder, inorder, preorderSize);
    }
    
}
