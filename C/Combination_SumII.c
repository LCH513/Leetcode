/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


void combination(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int step, int start, int* temp, int** ans){
    if(target == 0){
        ans[*returnSize] = malloc(sizeof(int) * step);
        memcpy(ans[*returnSize], temp, step * sizeof(int));
        returnColumnSizes[0][(*returnSize)++] = step;
        return;
    }
    if(start > candidatesSize-1){
        return;
    }

    if(target >= candidates[start]){
        temp[step] = candidates[start];
        combination(candidates, candidatesSize, target - candidates[start], returnSize, returnColumnSizes, step + 1, start + 1, temp, ans);
    }
    while(start < candidatesSize - 1 && (candidates[start] == candidates[start+1])){
        start++;
    }
    combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, step, start + 1, temp, ans);
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int** ans = malloc(sizeof(int*) * 256);
    int* temp = malloc(sizeof(int) * 256);
    *returnSize = 0;
    returnColumnSizes[0] = malloc(sizeof(int) * 256);
    /*for(int i = 0; i < candidatesSize; i++){
        printf("%d ",i);
        combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, i, temp, ans);
        while( i < candidatesSize-1 && (candidates[i] == candidates[i+1])){
            i++;
        }
    }*/
    combination(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, temp, ans);
    return ans;
}
