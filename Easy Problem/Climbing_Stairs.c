
/*recursive

int climbStairs(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

*/




int climbStairs(int n){
    int *a = (int*)calloc(46, sizeof(int));
    a[0] = 1;
    a[1] = 2;
    for(int i = 2; i < n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    return a[n-1];
}
