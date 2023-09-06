int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize, n = *obstacleGridColSize;
    int grid[m][n];
    int i, j;

    
    grid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    
    for (i = 1; i < m; i++) {
        grid[i][0] = obstacleGrid[i][0] == 1 ? 0 : grid[i - 1][0];
    }

    for (j = 1; j < n; j++) {
        grid[0][j] = obstacleGrid[0][j] == 1 ? 0 : grid[0][j - 1];
    }

    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            grid[i][j] = obstacleGrid[i][j] == 1 ? 0 : grid[i - 1][j] + grid[i][j - 1];
        }
    }

    return grid[m - 1][n - 1];
}
