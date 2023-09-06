int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    int temp = abs(target - (nums[0] + nums[1] + nums[2]));
    int result = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < numsSize - 2; i++){
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right){
            int dis = nums[i] + nums[left] + nums[right];
            if(dis == target){
                return target;
                break;
            }
            if(abs(target - dis) < temp){
                temp = abs(target - dis); 
                result = dis;
            }
            if(dis > target){
                right--;
            }
            if(dis < target){
                left++;
            }
        }
    }
    return result;
}
