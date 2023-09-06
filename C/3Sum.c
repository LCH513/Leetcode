/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0;
    int **ans = malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * numsSize * numsSize);
    for(int i = 0; i < numsSize - 2; i ++){
        if(i == 0 || nums[i] != nums[i - 1]){
            int left = i+1;
            int right = numsSize - 1;
            while(left < right){
                if((nums[i] + nums[left] + nums[right]) > 0){
                    right--;
                }
                else if((nums[i] + nums[left] + nums[right]) < 0){
                    left++;
                }
                else{
                    ans[(*returnSize)] = malloc(sizeof(int) * 3);
                    (*returnColumnSizes)[(*returnSize)] = 3;
                    ans[(*returnSize)][0] = nums[i];
                    ans[(*returnSize)][1] = nums[left];
                    ans[(*returnSize)][2] = nums[right];
                    (*returnSize)++;
                    left++;
                    while(nums[left] == nums[left-1] && left < right){
                        left++;
                    }
                }
                
            }
        }
    }
    return ans;
}
