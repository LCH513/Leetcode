

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int check = 0;
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            check = board[i][j];
            
            //if it is '.'
            if(check == 46){
                continue;
            }
            
            //column style
            for(int k = i + 1; k < boardSize; k++){
                if(check == board[k][j]){
                    return false;
                }
            }
            
            //row style
            for(int k = j + 1; k < boardSize; k++){
                if(check == board[i][k]){
                    return false;
                }
            }
            
            //set a variable to check if check ifself
            int delay = 1;
            
            //3*3
            for(int count_row = 0; count_row < 3; ++count_row){
                for(int count_col = 0; count_col < 3; ++count_col){
                    if(check == board[i - (i % 3) + count_row][j - (j % 3) + count_col]){
                        if(delay != 1){
                            return false;
                        }
                        delay--;
                    }
                } 
            }
            
        }
    }
    return true;
}
