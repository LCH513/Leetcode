bool isValid(char * s){
    char* temp = calloc(10000, sizeof(char));
    int pos = 0;
    while(*s != '\0'){
        switch(*s){
            case '(':
                temp[pos++] = ')';
                break;
            case '{':
                temp[pos++] = '}';
                break;
            case '[':
                temp[pos++] = ']';
                break;
            case ')':
            case '}':
            case ']':
                if(pos == 0 || temp[--pos] != *s){
                    return false;
                    break;
                }
        }
        s++;
    }
    if(pos != 0){
        return false;
    }
    else{
        return true;
    }
}
