int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }
    int count = 1;
    int current_num = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(current_num != nums[i]){
            current_num = nums[i];
            nums[count] = current_num;
            count++;
        }
    }
    return count;
}
