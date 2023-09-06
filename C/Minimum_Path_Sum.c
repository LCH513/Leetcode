int minPathSum(int** grid, int gridSize, int* gridColSize){
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(i && j){
                grid[i][j] += (grid[i-1][j]>grid[i][j-1])?grid[i][j-1]:grid[i-1][j];
            }
            else if(i){
                grid[i][j] += grid[i-1][j];
            }
            else if(j){
                grid[i][j] += grid[i][j-1];
            }
        }
    }
    return grid[gridSize-1][(*gridColSize)-1];
}
