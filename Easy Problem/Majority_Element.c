//Boyer–Moore majority vote algorithm
//divided the number into two type
//the majorityElement and not majorityElement

int majorityElement(int* nums, int numsSize){
    int count = 0;
    int result = 0;
    
    for(int i = 0; i < numsSize; i++){
        if(count == 0 || result == nums[i]){
            count ++;
            result = nums[i];
        }
        else {
            count --;
        }
    }
    return result;
}
