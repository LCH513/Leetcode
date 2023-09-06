int reverse(int x){
    int result = 0;
    while(x != 0){
        int temp = x % 10;
        if(result>INT_MAX/10||result<INT_MIN/10){
            return 0;
        }
        x = x / 10;
        result = result * 10 + temp;
    }
    return result;
}
