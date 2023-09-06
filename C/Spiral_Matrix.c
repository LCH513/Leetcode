/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int top = 0;
    int bottom = matrixSize - 1;
    int left = 0;
    int right = *matrixColSize - 1;
    int *result = malloc(sizeof(int) * matrixSize * (*matrixColSize));
    *returnSize = 0;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        for(int i = top; i <= bottom; i++){
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
        
    }
    return result;
}
