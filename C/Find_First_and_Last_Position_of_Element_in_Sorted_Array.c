

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = (int*)calloc(2, sizeof(int));
    result[0] = -1;
    result[1] = -1;
    
    if(numsSize == 0){
        return result;
    }
    
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) / 2;
    int temp = 0;
    while(left < right){
        if(nums[mid] == target){
            temp = mid;
            break;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        mid = (left + right) / 2;
        temp = mid;
    }
    while(mid >= 0 && nums[mid] == target){
        result[0] = mid;
        mid--;
    }
    while(temp <= (numsSize-1) && nums[temp] == target){
        result[1] = temp;
        temp++;
        
    }
    return result;
}
