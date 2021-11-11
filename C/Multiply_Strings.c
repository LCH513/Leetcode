char * multiply(char * num1, char * num2){
    if(*num1 == '0' || *num2 == '0'){
        return "0";
    }
    int length_1 = strlen(num1);
    int length_2 = strlen(num2);
    int total_length = length_1 + length_2;
    int* temp = (int*)calloc(total_length,sizeof(int));
    
    for(int i = length_1 - 1; i > -1; i--){
        for(int j = length_2 - 1; j > -1; j--){
            temp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    
    //check if need to carry or not
    for(int i = total_length - 1; i > 0; i--){
        temp[i-1] += (temp[i] / 10);
        temp[i] %= 10;
    }
    
    char* result = (char*)calloc(total_length+1,sizeof(char));
    int index_result = 0;
    int index_temp = 0;
    
    //if there don't have to carry, move to next position
    if(temp[0] == 0){
        index_temp++;
    }
    
    while(index_temp < total_length){
        result[index_result] = temp[index_temp] + '0';
        index_result++;
        index_temp++;
    }
    
    return result;
    
}
