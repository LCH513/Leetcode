char * longestCommonPrefix(char ** strs, int strsSize){
    char* result;
  
    //start to compare from the first string
    result = strs[0];
  
    int index = 0;
    
 
    for(int i = 1; i < strsSize; i++){
        //if have the same character,compare with next character
        while(result[index] && strs[i][index] && result[index] == strs[i][index]){
            index++;
        }
      
        //if not the same, stop finding
        result[index] = '\0';
      
        //initiate index
        index = 0;
    }

   
        
    return result;
}
