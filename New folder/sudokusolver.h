#include <vector>

bool in_row(std::vector<std::vector<char>> & board , int i, int j ,char val);

bool in_col(std::vector<std::vector<char>> & board , int i, int j , char val);


bool in_square(std::vector<std::vector<char>> & board , int i, int j , char val);

bool allFilled(std::vector<std::vector<char>> & board);

bool solver(std::vector<std::vector<char>> & board);
void solveSudoku(std::vector<std::vector<char>>& board) {
    solver(board);


}


bool solver(std::vector<std::vector<char>> & board)
{
    if (allFilled(board))
    {
        return true ;
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.at(0).size(); j ++)
        {
            if (board.at(i).at(j) == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (!in_row(board,i,j,c) && !in_col(board,i,j,c) && !in_square(board, i, j, c) )
                    {
                        *(board.at(i).begin() + j) = c;
                        if (!solver(board))
                        {
                            *(board.at(i).begin() + j) = '.';
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool allFilled(std::vector<std::vector<char>> & board)
{
    for (std::vector<char> v: board)
    {
        for (char c: v)
        {
            if (c == '.') return false;
        }
    }
    return true;
}

bool in_row(std::vector<std::vector<char>> & board , int i, int j , char val)
{
    for (int c = 0; c < 9 ; c ++) 
    {
        if (board.at(i).at(c) == val)
        {
            return true;
        }
    }
    return false;
}

bool in_col(std::vector<std::vector<char>> & board , int i, int j, char val)
{
    for (int r = 0; r < 9; r ++)
    {
        if (board.at(r).at(j) == val)
        {
            return true;
        }
    }
    return false;
}


bool in_square(std::vector<std::vector<char>> & board , int i, int j, char val)
{
    int start_r = i /3 * 3;
    int start_c = j / 3 * 3;
    for (int r = start_r; r < start_r + 3; r++)
    {
        for (int c = start_c; c < start_c + 3 ; c++)
        {
            if (board.at(r).at(c) == val)
            {
                return true;
            }
        }
    }
    return false;
}
