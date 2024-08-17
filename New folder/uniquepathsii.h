#include <vector>
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        std::size_t pathCount[obstacleGrid.size()][obstacleGrid.at(0).size()];
        std::size_t m = obstacleGrid.size();
        std::size_t n = obstacleGrid.at(0).size(); 
        pathCount[m-1][n-1] = 1;
        if (obstacleGrid.at(m-1).at(n-1) == 1)
        {
            return  0;
        }
        for (int j = n-1; j >= 0; j--)
        {
            for (int i = m-1; i >= 0; i--)
            {
                if (i == m-1 && j == n-1) continue;
                else if (obstacleGrid.at(i).at(j) == 1) 
                {
                    pathCount[i][j] = 0;
                }
                else if (i == m-1)
                {
                    pathCount[i][j] = pathCount[i][j+1];
                } else if (j == n-1)
                {
                    pathCount[i][j] = pathCount[i+1][j];
                } else
                {
                    pathCount[i][j] = pathCount[i+1][j] + pathCount[i][j+1];
                }
            }
        }


        return pathCount[0][0];

    }