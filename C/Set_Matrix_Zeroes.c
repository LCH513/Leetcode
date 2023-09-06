void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    bool row = false;
    bool col = false;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == 0){
                if(i == 0){
                    row = true;
                }
                if(j == 0){
                    col = true;
                }
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < matrixSize; i++){
        for(int j = 1; j < *matrixColSize; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(row){
        for(int i = 0; i < *matrixColSize; i++){
            matrix[0][i] = 0;
        }
    }
    if(col){
        for(int i = 0; i < matrixSize; i++){
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
