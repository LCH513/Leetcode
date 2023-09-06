char * countAndSay(int n){
    if(n == 1){
        return "1";
    }
    char *s = countAndSay(n-1);
    int length = strlen(s);
    char *ans = (char*)malloc(4463*sizeof(char));
    int index = 0;
    char cur = *s;
    int count = 1;
    for(int i = 1; i < length; i++){
        char c = *(s+i);
        if(c == cur){
            count++;
        }
        else{
            *(ans + index++) = '0' + count;
            *(ans + index++) = cur;
            cur = c;
            count = 1;
        }
    }
    *(ans + index++) = '0' + count;
    *(ans + index++) = cur;
    *(ans + index) = '\0';
    return ans;
}
