int findPeakElement(int* nums, int numsSize){
    int right = numsSize - 1;
    int left = 0;
    while(left <= right){
        int mid = (left + right)/2;
        if(mid < numsSize-1 && (nums[mid + 1] > nums[mid])){
            left = mid + 1;
        }
        else if(mid > 0 && (nums[mid-1] > nums[mid])){
            right = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
