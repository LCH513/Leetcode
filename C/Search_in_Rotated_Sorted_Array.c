//solve in O(log(n))

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while(left <= right){
        mid = (left + right) / 2;
        
        //target not in array
        if(left == right && nums[left] != target){
            return -1;
        }
        
        //find the target
        else if(nums[mid] == target){
            return mid;
        }
        
        //target is in the right side
        else if(nums[left] > target && nums[mid] < target){
            left = mid;
        }
        
        //target is in the left side
        else if(nums[right] < target && nums[mid] > target){
            right = mid;
        }
        
        //otherwise
        else if(nums[left] > target || nums[right] < target){
            if(nums[mid] < nums[right]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        //maybe in order, binary search
        else{
            if(target < nums[mid]){
                right = mid - 1;
            }
            if(target > nums[mid]){
                left = mid + 1;
            }
        }
    }
    return -1;
}
