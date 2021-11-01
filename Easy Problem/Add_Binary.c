char * addBinary(char * a, char * b){
    int carry = 0;
    int length_a = strlen(a);
    int length_b = strlen(b);
    int max_length = (length_a > length_b)?length_a:length_b; 
    char *result = (char*)malloc((max_length + 2) * sizeof(char));
    result[max_length+1] = 0;
    for(int i = 0; i < max_length; i ++,length_a--, length_b--){
        int compare_a = (length_a > 0) ? a[length_a - 1] - '0': 0;
        int compare_b = (length_b > 0) ? b[length_b - 1] - '0': 0;
        int sum = compare_a + compare_b + carry;
        carry = sum / 2;
        sum %= 2;
        result[max_length - i] = sum + '0';
        
    }
    if(carry){
        result[0] = '1';
        return result;
    }
    return result + 1;
}
