bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    
    long int new_x = abs(x);
    long int reverse = 0;
    while(new_x != 0){
        reverse *= 10;
        reverse += (new_x %10);
        new_x /= 10;
    }
    
    if(reverse == x){
        return true;
    }
    
    return false;
}
