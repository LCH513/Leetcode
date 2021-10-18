//using binary search

int searchInsert(int* nums, int numsSize, int target){
    int index = 0;
    int end = numsSize;
    while(index < end){
        if(nums[index] == target){
            return index;
        }
        else if(nums[index] < target){
            index = (index + end + 1) / 2;
        }
        else if(nums[index] > target){
            end = index;
            index = (0 + index) / 2;
            
        }
    }
    return index;
}
