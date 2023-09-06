void rotate(int* nums, int numsSize, int k){

    k = k % numsSize;
    if(k == 0 || numsSize == 1){
        return;
    }
    int i = 0;
    int j = numsSize - 1;
    while(i < j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    
    i = 0;
    j = k - 1;
    while(i < j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    
    i = k;
    j = numsSize - 1;
    while(i < j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    
}  
