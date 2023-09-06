

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void per(int **arr,int *count,int numsSize,int *nums,int *visited,int *res,int total,int k)
{
    if(k==numsSize){
        if(*count==total){return;}
        int *temp = malloc(sizeof(int) * numsSize);
        memcpy(temp,res,sizeof(int) * numsSize);
        arr[(*count)++] = temp;
    }
    else{
        for(int i=0;i<numsSize;i++){
            if(visited[i] == 0){
                res[k] = nums[i];
                visited[i] = 1;
                per(arr,count,numsSize,nums,visited,res,total,k+1);
                visited[i] = 0;
            }
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int total = 1;
    int count = 0;
    for(int i = numsSize; i > 0; --i){
        total *= i;
    }
    *returnSize = total;

    int **arr = malloc(total * sizeof(int*));
    int *visited = calloc(numsSize,sizeof(int));
    int *res = calloc(numsSize, sizeof(int));
    
    per(arr, &count, numsSize, nums, visited, res, total, 0);

    int *ret = malloc(total * sizeof(int));
    for(int i = 0; i < total; i++){
        ret[i] = numsSize;
    }
    *returnColumnSizes = ret;
    free(visited);
    free(res);
    return arr;
}
