bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize - 1;
    int col = 0;
    bool flag = false;
    while(row >= 0 && col < *matrixColSize){
        if(matrix[row][col] == target){
            flag = true;
            break;
        }
        else if(matrix[row][col] < target){
            col++;
            continue;
        }
        else{
            row--;
        }       
    }
    return flag;
}
