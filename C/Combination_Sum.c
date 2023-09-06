/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void Combination(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int step, int start, int* temp, int** result){
    if(target == 0){
        result[*returnSize] = malloc(sizeof(int) * step);
        memcpy(result[*returnSize], temp, step*sizeof(int));
        returnColumnSizes[0][(*returnSize)++] = step;
        return;
    }
    if(start > candidatesSize-1){
        return;
    }
    
    if(target - candidates[start] >= 0){
        temp[step] = candidates[start];
        Combination(candidates, candidatesSize, target-candidates[start], returnSize, returnColumnSizes, step+1, start, temp, result);
    }

    Combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, step, start+1, temp, result);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int** result = malloc(sizeof(int*) * 256);
    int* temp = malloc(sizeof(int) * 50);
    returnColumnSizes[0] = malloc(sizeof(int) * 256);
    *returnSize = 0;

    Combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, temp, result);

    return result;
    
}
