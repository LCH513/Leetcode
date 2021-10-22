//ex: 'ACB' = 26*26*1 + 26*3 + 2

int titleToNumber(char * columnTitle){
    int length = strlen(columnTitle);
    int count = 0;
    int total = 0;
    for(int i = length - 1; i >= 0; i--){
        int temp = columnTitle[i] - 64;
        total = total + pow(26,count) * temp;
        count++;
    }
    
    return total;
}
