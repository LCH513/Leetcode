void Reverse(int* nums, int start, int end){
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int target = -1;
    for(int i = numsSize - 1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            target = i-1;
            break;
        }
    }
    if(target != -1){
        for(int i = numsSize - 1; i > target; i--){
            if(nums[target] < nums[i]){
               int temp = nums[i];
               nums[i] = nums[target];
               nums[target] = temp;
               break;
           }
        }
    }
    if(numsSize > 2){
        Reverse(nums,target+1,numsSize-1);
    }
    if(numsSize <= 2 && target == -1){
        Reverse(nums,target+1,numsSize-1);
    }
    return;
}
