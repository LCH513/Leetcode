void visit(char** grid, int row, int col, int gridSize, int* gridColSize){
    if(row < 0 || col < 0){
        return;
    }
    if(row >= gridSize || col >= gridColSize[row]){
        return;
    }
    if(grid[row][col] == '0'){
        return;
    }
    grid[row][col] = '0';
    visit(grid, row-1, col, gridSize, gridColSize);
    visit(grid, row+1, col, gridSize, gridColSize);
    visit(grid, row, col-1, gridSize, gridColSize);
    visit(grid, row, col+1, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == '1'){
                visit(grid, i, j, gridSize, gridColSize);
                count++;
            }
        }
    }
    return count;
}
