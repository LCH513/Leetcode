int lengthOfLastWord(char * s){
    int length = strlen(s) - 1;
    int count = 0;
    while(s[length] == 32){
        length--;
    }
    while(length != -1 && s[length] != 32){
        length--;
        count++;
    }
    return count;
}
