

int romanToInt(char * s){
    int sum = 0;
    int length = strlen(s);
    int *temp = calloc(length + 1,sizeof(int));
    for(int i = 0; i < length; i++){
        if(s[i] == 'I'){
            temp[i] = s[i] - 72;
        }
        else if(s[i] == 'V'){
            temp[i] = s[i] - 81;
        }
        else if(s[i] == 'X'){
            temp[i] = s[i] - 78;
        }
        else if(s[i] == 'L'){
            temp[i] = s[i] - 26;
        }
        else if(s[i] == 'C'){
            temp[i] = s[i] + 33;
        }
        else if(s[i] == 'D'){
            temp[i] = s[i] + 432;
        }
        else if(s[i] == 'M'){
            temp[i] = s[i] + 923;
        }
    }
    for(int i = 0; i < length; i++){
        if(temp[i] < temp[i+1]){
            sum += temp[i+1] - temp[i];
            i++;
        }
        else{
            sum += temp[i];
        }
    }
    return sum;
}
