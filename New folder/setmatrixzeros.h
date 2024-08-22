#include <vector>
#include <map>
#include <string.h>

void foundZeros(std::vector<std::vector<int>>& matrix, int i, int j, int * rowToSeenZero,int *colToSeenZero)
{

    
    for (int c = 0; c < matrix.at(0).size(); c++)
    {   
        if (rowToSeenZero[i] == 1) break;
        if (matrix.at(i).at(c) != 0 || (matrix.at(i).at(c) == 0 && colToSeenZero[c] == 1  ) )
        {
            matrix.at(i).at(c) = 0;
        } else
        {
            foundZeros(matrix,i,c, rowToSeenZero, colToSeenZero);
        }
    }
    colToSeenZero[j] = 1;
    
    for (int r = 0; r < matrix.size(); r ++)
    {
        if (colToSeenZero[j] == 1) break;
        if (matrix.at(r).at(j) != 0 || (matrix.at(r).at(j) == 0 && rowToSeenZero[i] == 0  ) )
        {
            matrix.at(r).at(j) = 0;
        }
        else
        {
            rowToSeenZero[r] = 1;
            foundZeros(matrix,r,j, rowToSeenZero, colToSeenZero);
        }
    }
    rowToSeenZero[i] = 1;

}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int rowToSeenZero[matrix.size()];
    int colToSeenZero[matrix.at(0).size()];
    memset(rowToSeenZero, 0, matrix.size() * sizeof(int));
    memset(colToSeenZero,0, matrix.at(0).size() * sizeof(int));
    for (int i = 0; i < matrix.size(); i ++)
    {
        for (int j = 0; j < matrix.at(0).size(); j ++)
        {
            if (matrix.at(i).at(j) != 0)
            {
                if (rowToSeenZero[i] || colToSeenZero[j])
                {
                    matrix.at(i).at(j) = 0;
                }
                continue;
            } else
            {
                if (!colToSeenZero[j])
                {
                for (int r = i; r >= 0; r--)
                    {
                        matrix.at(r).at(j) = 0;
                    }
                }
                if (!rowToSeenZero[i])
                {
                for (int c = j; c >= 0; c--)
                    {
                        matrix.at(i).at(c) = 0;
                    }
                }
          
                rowToSeenZero[i] = 1;
                colToSeenZero[j] = 1;
            }


        }
    }

            
}