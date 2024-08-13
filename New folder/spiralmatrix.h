#include <vector> 

std::vector<int>spiralOrder(std::vector<std::vector<int>>& matrix) {
            int m = matrix.size();
        int n = matrix.at(0).size();
        
        if (m == 1){
                return std::vector<int>(matrix.at(0));
        }
        
        int startRow = 0;
        int startColumn = 0;
        int endRow = m - 1;
        int endColumn = n - 1;
        int i, j;
        std::vector<int> spiral;
        if (n == 1)
        {
                for (int k = 0 ; k < m; k ++)
                {
                        spiral.push_back(matrix.at(k).at(0));
                }
                return spiral;
        }
        while (m > 0 && n > 0)
        {

                
                for (j = startColumn; j < startColumn + endColumn; j++)
                {
                        spiral.push_back(matrix.at(startRow).at(j));
                }
                if (m == 1)
                {
                        spiral.push_back(matrix.at(startRow).at(j));
                        return spiral;
                }
                for (i = startRow; i < startRow + endRow; i ++)
                {
                        spiral.push_back(matrix.at(i).at(j));
                }
                if (n == 1)
                {
                        spiral.push_back(matrix.at(i).at(j));
                        return spiral;
                }
                for (j = endColumn + startColumn; j > startColumn; j--)
                {
                        spiral.push_back(matrix.at(i).at(j));
                }
                for (i = endRow + startRow; i > startRow; i--)
                {
                        spiral.push_back(matrix.at(i).at(j));
                }
                startRow += 1;
                startColumn += 1;
                m -= 2;
                n -= 2;
                endRow = m-1;
                endColumn = n-1;
        }
        if (m == n && (m % 2 == 1 || m %  2 == -1)) 
        {
                spiral.push_back(matrix.at(i).at(j));
        }
        return spiral;
}
