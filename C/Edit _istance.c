int minDistance(char * word1, char * word2){
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    int dp[length1+1][length2+1];
    for(int i = 0; i <= length1; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= length2; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= length1; i++){
        for(int j = 1; j <= length2; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            int temp = dp[i-1][j-1]<dp[i-1][j]?dp[i-1][j-1]:dp[i-1][j];
            temp = temp<dp[i][j-1]?temp:dp[i][j-1];
            dp[i][j] = 1+temp;
        }
    }
    return dp[length1][length2];
}
