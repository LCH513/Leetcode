void sortColors(int* nums, int numsSize){
    int *count = calloc(sizeof(int),3);
    int pos = 0;
    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    for(int i = 0; i < numsSize; i++){
        while(count[pos] == 0){
            pos++;
        }
        nums[i] = pos;
        count[pos]--;
    }
    return nums;
}
