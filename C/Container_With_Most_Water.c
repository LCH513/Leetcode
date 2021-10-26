int maxArea(int* height, int heightSize){
    int head = 0;
    int tail = heightSize - 1;
    int area_max = 0;
    while(head < tail){
        int area_temp = (tail - head) * ((height[head] < height[tail])?height[head++]:height[tail--]);
        if(area_temp > area_max){
            area_max = area_temp;
        }
    }
    return area_max;
}
