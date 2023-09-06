bool search(char** board, int boardSize, int* boardColSize, char * word, int** visit, int i, int j, int pos){
    if(strlen(word) == pos){
        return true;
    }
    //check above value
    if(i > 0 && board[i-1][j] == word[pos] && visit[i-1][j] != 1){
        visit[i-1][j] = 1;
        if(search(board, boardSize, boardColSize, word, visit, i-1, j ,pos+1)){
            return true;
        }
        visit[i-1][j] = 0;
    }
    //check down value
    if(i < boardSize - 1 && board[i+1][j] == word[pos] && visit[i+1][j] != 1){
        visit[i+1][j] = 1;
        if(search(board, boardSize, boardColSize, word, visit, i+1, j ,pos+1)){
            return true;
        }
        visit[i+1][j] = 0;
    }
    //check left value
    if(j > 0 && board[i][j-1] == word[pos] && visit[i][j-1] != 1){
        visit[i][j-1] = 1;
        if(search(board, boardSize, boardColSize, word, visit, i, j-1 ,pos+1)){
            return true;
        }
        visit[i][j-1] = 0;
    }
    //check right value
    if(j < *boardColSize - 1 && board[i][j+1] == word[pos] && visit[i][j+1] != 1){
        visit[i][j+1] = 1;
        if(search(board, boardSize, boardColSize, word, visit, i, j+1 ,pos+1)){
            return true;
        }
        visit[i][j+1] = 0;
    }

    return false;
}



bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int** visit = calloc(sizeof(int*) , boardSize);
    for(int i = 0; i < boardSize; i++){
        visit[i] = calloc(sizeof(int) , (*boardColSize));
    }


    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] == word[0]){
                visit[i][j] = 1;
                if(search(board, boardSize, boardColSize, word, visit, i, j ,1)){
                    return true;
                }
                visit[i][j] = 0;
            }

        }
    }
    return false;
}
