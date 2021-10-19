/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char* set[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int size = 1;
    int length = strlen(digits);
    //if there has no digit
    if(length == 0){
        *returnSize = 0;
        return NULL; 
    }
    //caculate how many combinations by ASCII
    for(int i = 0; i < length; i++){
        if(digits[i] == '1'){
            continue;
        }
        
        size *= strlen(set[digits[i] - '0']);
    }
    
    
    *returnSize = size;
    int temp_round_length = size;
    
    char** result = (char**)calloc(size,sizeof(char*));
    for(int i = 0; i < size; i++){
        result[i] = (char*)calloc(length+1,sizeof(char));
    }
    int count = 0;
    
    for(int i = 0; i < length; i++){
        
        if(digits[i] == '1'){
            continue;
        }
        
        int temp_length = strlen(set[digits[i] - '0']);
      
        //Rule for configuring numbers
        temp_round_length /= temp_length;
        
        //set the number
        for(int j = 0; j < size; j++){
            result[j][count] = set[digits[i] - '0'][j / temp_round_length % temp_length];
        }
        count++;
    }
    
    return result;
}
