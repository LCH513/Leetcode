int removeElement(int* nums, int numsSize, int val){
    //A value to record the new array position
    int pos = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
}
