int findKthLargest(int* nums, int numsSize, int k){
    int low = 0;
    int high = numsSize - 1;
    int out = 0;
    do{
        int pivot = nums[high];
        out = low;
        for(int i = low; i < high; i++){
            if(nums[i] >= pivot){
                int temp = nums[i];
                nums[i] = nums[out];
                nums[out++] = temp;
            }
        }
        nums[high] = nums[out];
        nums[out] = pivot;
        if(out < k - 1){
            low = out + 1;
        }
        else{
            high = out-1;
        }
    }while(out != (k - 1));
    int ans = nums[out];
    return ans;
}
