
// m = total numbers in nums1
// n = total numbers in nums2

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int total_length = nums1Size - 1;
    
    while((m-1) >= 0 && (n-1) >= 0){
        if(nums1[m - 1] < nums2[n - 1]){
            nums1[total_length] = nums2[n - 1];
            total_length -= 1;
            n -= 1;
        }
        else{
            nums1[total_length] = nums1[m - 1];
            total_length -= 1;
            m -= 1;
        }
    }
    while(n - 1 >= 0){
        nums1[total_length] = nums2[n - 1];
        total_length -= 1;
        n -= 1;
    }
}
