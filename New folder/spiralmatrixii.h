#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix;
    int mat [n][n];
    int toInsert = 1;
    int start = 0;
    int end = n;
    matrix.reserve(n);
    for (int i = 0; i < n; i ++)
    {   
        std::vector<int> blank;
        for (int j = 0; j < n; j++)
        {
            blank.push_back(0);
        }
        matrix.push_back(blank);
    }
    if (n == 1)
    {
        return {{1}};
    }
    if (n == 2)
    {
        return {{1,2}, {4,3}};
    }

    for (int dim = n; dim > 1; dim -= 2)
    {
        for (int c = 0 ; c < 4; c ++)
        {
            switch (c)
            {
            case 0/* constant-expression */:
                for (int i = 0; i < dim - 1; i ++)
                {
                    matrix.at(start).at(i + start) = toInsert++;
                }
                break;
            case 1:
                for (int i = 0; i < dim - 1; i ++)
                {
                    matrix.at(i + start).at(end - 1) = toInsert++;
                }
                break;
            case 2:
                for (int i = dim - 1; i > 0; i --)
                {
                    matrix.at(end - 1).at(i + start) = toInsert ++;
                }
                break;
            case 3:
                for (size_t i = dim-1; i > 0 ; i--)
                {
                    /* code */
                    matrix.at(i + start).at(start) = toInsert++;
                }
                
                break;
            default:
                break;
            }
        }
        start += 1;
        end -= 1;
    }
    if (n % 2 == 1)
    {
        matrix.at(n / 2).at(n/2) = toInsert++;
    }
    return matrix;
}