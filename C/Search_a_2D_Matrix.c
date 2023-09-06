bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    int col = *matrixColSize - 1;
    while(row < matrixSize && col > -1){
        int cur = matrix[row][col];
        if(cur == target){
            return true;
        }
        else{
            if(target > cur){
                row++;
            }
            else{
                col--;
            }
        }
    }
    return false;
}
