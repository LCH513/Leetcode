/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void choose(int l, int r, int k, bool* arr, int** ans, int* returnSize){
    if(l == r+1){
        int a = 0;
        for(int i = 1; i <= r; i++){
            if(arr[i]){
                ans[*returnSize][a++] = i;
            }
        }
        (*returnSize)++;
        return;
    }
    if(k >= 1){
        arr[l] = true;
        choose(l+1, r, k-1, arr, ans, returnSize);
    }
    if(r - l + 1 > k){
        arr[l] = false;
        choose(l+1, r, k, arr, ans, returnSize);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    long long total = 1;
    for ( int i = 0; i < k; ++i ){
        total *= ( n - i );
    }
        
    for ( int i = 0; i < k; ++i ){
        total /= (i+1);
    }
        

    bool arr[n+1];
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * total);
    int** ans = malloc(sizeof(int*) * total);
    for(int i = 0; i < total; i++){
        ans[i] = malloc(sizeof(int)*k);
        (*returnColumnSizes)[i] = k;
    }
    choose(1,n,k,arr,ans,returnSize);
    return ans;
}
