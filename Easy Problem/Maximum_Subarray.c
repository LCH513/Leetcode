int maxSubArray(int* nums, int numsSize){
    int maximum = nums[0];
    int temp = 0;
    for(int i = 0; i < numsSize; i++){
        temp += nums[i];
        
        if(maximum < temp){
            maximum = temp;
        }
        
        if(temp < 0){
            temp = 0;
        }
    }
    return maximum;
}
