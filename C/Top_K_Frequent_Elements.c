/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct hashtable{
    int val;
    int count;
};

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int cmphfunc (const void * a, const void * b)
{
   return ((struct hashtable*)b) -> count - ((struct hashtable*)a) -> count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
     
    int* ans = calloc(k,sizeof(int));
    *returnSize = k;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    struct hashtable *table = calloc(sizeof(struct hashtable), numsSize);

    int pos = 0;
    table[0].val = nums[0];
    table[0].count = 1;
    
    for(int i = 1; i < numsSize; i++){
        if(nums[i] != nums[i-1]){
            pos++;
            table[pos].val = nums[i];
            table[pos].count += 1;
        }
        else{
            table[pos].val = nums[i];
            table[pos].count += 1;
        }
    }
    qsort(table, (pos+1), sizeof(struct hashtable), cmphfunc);
    for(int i = 0; i < k; i++){
        ans[i] = table[i].val;
    }
    return ans;
    
    
}
