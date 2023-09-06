/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int * nums, int x, int y)
{
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

void getResult(int ** out, int * nums, int numsSize, int start, int * size)
{
    if(start == numsSize)
    {
        out[*size] = (int *)malloc(numsSize*sizeof(int));
        memcpy(out[(*size)++], nums, numsSize*sizeof(int));
        return;
    }
    bool check[21] = {0};
    for(int i = start; i < numsSize; i++)
    {
        if(check[nums[i] + 10]) continue;
        check[nums[i] + 10] = true;
        swap(nums, start, i);
        getResult(out, nums, numsSize, start + 1, size);
        swap(nums, start, i);
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ** result = (int **)malloc(50000*sizeof(int *));
    int * temp = (int *)malloc(numsSize*sizeof(int)); 
    int size = 0;
    getResult(result, nums, numsSize, 0, &size);
    *returnColumnSizes = (int *)malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
        (*returnColumnSizes)[i] = numsSize;
    *returnSize = size;
    return result;
}
