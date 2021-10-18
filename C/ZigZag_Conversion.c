char * convert(char * s, int numRows){
    int length = strlen(s);
    int count = 0;
    char* result = calloc(length+1, sizeof(char));
    
    //If the output is in order
    if(length <= numRows || numRows == 1){
        return s;
    }
    
    for(int i = 0; i < numRows; i++){
        //the rule
        for(int j = i; j < length; j += 2 * (numRows - 1)){
            result[count++] = s[j];
            //if not the first or last number of a Column, we have to find the previous number in row style
            if(i != 0 && i != numRows - 1){
                int temp = j + 2 * (numRows - 1) - 2 * i;
                if(temp < length){
                    result[count++] = s[temp];
                }
            }
        }
    }
    return result;
}
