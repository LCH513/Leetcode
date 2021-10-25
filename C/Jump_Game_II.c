//greedy

int jump(int* nums, int numsSize){   
    int end = 0;
    int far = 0;
    int count = 0;
    for(int i = 0; i < numsSize - 1; i++){
        far = (far>i + nums[i])?far: i +nums[i];
        //jump to next round
        if(i == end){
            count++;
            end = far;
            if(end > numsSize - 1){
                break;
            }
        }
    }
    return count;
}
