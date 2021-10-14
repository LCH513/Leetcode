int lengthOfLongestSubstring(char * s){
    int *ascii = calloc(128,sizeof(int));
    int start = 1;
    char *check = s;
    int output = 0;
    int len = strlen(s);
    
    for(int i = 1; i <= len; i ++){
    
        //check if the character is repeated
        if(ascii[*check] >= start){
            start = ascii[*check] + 1;
        }
        
        //character is not repeated
        else{
            if(i - start +1 >= output){
                output = i - start + 1;
            }
        }
        ascii[*check] = i;
        *check++;
    }
    return output;
}
