/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int check(int** ans, int* returnSize, int** returnColumnSizes, int* sub, int pos){
    for(int i = 0; i < *returnSize; i++){
        if((*returnColumnSizes)[i] == pos){         
            if(0 == memcmp(ans[i], sub, pos*sizeof(int))){
                return 1;
                break;
            }
        }
    }
    return 0;
}

void duplicate(int* nums, int** ans, int numsSize, int* returnSize, int** returnColumnSizes, int* sub, int start, int pos){
    if(start == numsSize){
        if(0 == check(ans, returnSize, returnColumnSizes, sub, pos)){
            ans[*returnSize] = calloc(sizeof(int) , pos);
            memcpy(ans[*returnSize], sub, sizeof(int) * pos);
            (*returnColumnSizes)[(*returnSize)++] = pos;
            return;
        }
        return;
    }
    sub[pos++] = nums[start];
    duplicate(nums, ans, numsSize, returnSize, returnColumnSizes, sub, start + 1, pos);
    pos--;
    duplicate(nums, ans, numsSize, returnSize, returnColumnSizes, sub, start + 1, pos);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int** ans = calloc(sizeof(int*) , pow(2,numsSize));
    *returnColumnSizes = calloc(sizeof(int) , pow(2,numsSize));
    int* sub = calloc(sizeof(int) , numsSize);
    duplicate(nums, ans, numsSize, returnSize, returnColumnSizes, sub, 0, 0);
    return ans;
}
