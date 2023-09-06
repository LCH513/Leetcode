void backtrack(int* nums, int numsSize, int** ans, int* sub, int* returnSize, int** returnColumnSizes, int start, int pos){
    if(start == numsSize){
        ans[*returnSize] = calloc(sizeof(int), pos);
        memcpy(ans[*returnSize], sub, sizeof(int) * pos);
        (*returnColumnSizes)[(*returnSize)++] = pos;
        return;
    }

    sub[pos++] = nums[start];
    backtrack(nums, numsSize, ans, sub, returnSize, returnColumnSizes, start + 1, pos);
    pos--;
    backtrack(nums, numsSize, ans, sub, returnSize, returnColumnSizes, start + 1, pos);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** ans = calloc(sizeof(int*) , pow(2,numsSize));
    *returnColumnSizes = calloc(sizeof(int) , pow(2, numsSize));
    int* sub = calloc(sizeof(int) , numsSize);
    backtrack(nums,numsSize, ans, sub, returnSize, returnColumnSizes, 0, 0);
    return ans;
}
