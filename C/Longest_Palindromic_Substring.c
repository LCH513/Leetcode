
//find longest palindromic substring
int findLPS(char * s, int start, int end, int length){
    for(; start >= 0 && end < length; start-- , end++){
        if(s[start] != s[end]){
            break;
        }
    }
    return end - start - 1;
}





char * longestPalindrome(char * s){
    int length = strlen(s);
    int max = 0;
    int index = 0;
    for(int i = 0; i < length; i++){
        int count_odd = findLPS(s, i, i, length);  //count in odd
        int count_even = findLPS(s, i, i+1, length); //count in even
        if(max < count_odd || max < count_even){
            if(count_odd > count_even){
                index = i - count_odd / 2;
            }
            else{
                index = i - count_even / 2 + 1;
            }
            max = (count_odd > count_even)?count_odd : count_even;
        }
    }
    char* result = calloc(max + 1, sizeof(char));
    memcpy(result, &s[index], max); // copy the palindrome section
    return result;
}
