

int uniquePaths(int m, int n) {
        
    int grid[m][n];
    if (m == 1 || n == 1) return 1;

    grid[m-1][n-1] = 1;

    for (int j = n-1; j >= 0; j --)
    {
        for (int i = m-1; i >= 0; i--)
        {
            if (i == m-1 && j == n-1) continue;
            else if (i == m-1) grid[i][j] = grid[i][j+1];
            else if (j == n-1) grid[i][j] = grid[i+1][j];
            else grid[i][j] = grid[i+1][j] + grid[i][j+1];


        }
    }
    return grid[0][0];

}