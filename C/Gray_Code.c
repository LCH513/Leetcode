/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int total = 1 << n;
    *returnSize = total;
    int* ans = malloc(sizeof(int) * total);
    for(int i = 0; i < total; i++){
        ans[i] = i ^ (i >> 1);
    }
    return ans;
    
}
