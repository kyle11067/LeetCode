#include <vector>
#include <string>

// ".Q.."
// "...Q"
// "Q..."
// "..Q."

bool inRow(int row, int n, const std::vector<std::string> & board)
{
    for (int i = 0; i < n; i++)
    {
        if (board.at(row).at(i) == 'Q')
        {
            return true;
        }
    }
    return false;
}

bool inCol(int col, int n, const std::vector<std::string> & board)
{
    for (int i = 0; i < n; i++)
    {
        if (board.at(i).at(col) == 'Q')
        {
            return true;
        }
    }
    return false;
}

bool inDiag(int row, int col, int n, const std::vector<std::string> & board)
{
    int row_ = row;
    int col_ = col;
    while (row_ >= 0 && col_ >= 0)
    {
        if (board.at(row_).at(col_) == 'Q')
        {
            return true;
        }
        row_ --;
        col_ --;
    }
    row_ = row;
    col_ = col;
    while (row_ < n && col_ < n)
    {
        if (board.at(row_).at(col_) == 'Q')
        {
            return true;
        }
        row_ ++;
        col_ ++;
    }
    row_ = row;
    col_ = col;
    while (row_ >= 0 && col_ < n)
    {
        if (board.at(row_).at(col_) == 'Q')
        {
            return true;
        }
        row_ --;
        col_ ++;
    }
    row_ = row;
    col_ = col;
    while (row_ < n && col_ >= 0)
    {
        if (board.at(row_).at(col_) == 'Q')
        {
            return true;
        }
        row_ ++;
        col_ --;
    }
    return false;
}
bool valid(int row, int col, int n, const std::vector<std::string> & board)
{
    if (!inRow(row,n,board) && !inCol(col,n,board) && !inDiag(row,col,n,board))
    {
        return true;
    }
    return false;
}

bool findConfig(const int n, int row, std::vector<std::string> & board, std::vector<std::vector<std::string>>  & configs)
{
    if (row >= n)
    {
        configs.push_back(board);
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (valid(row,i,n, board))
        {
            board.at(row).at(i) = 'Q';
            (findConfig(n, row+1, board,configs));
            board.at(row).at(i) = '.';
        } else
        {
            continue;
        }
    }
    return true;
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> board;    
    std::vector<std::vector<std::string>> configs;
    const int n_ = n;
    for (int i = 0; i < n; i ++)
    {
        std::string row;
        for (int j = 0; j < n; j ++)
        {
            row.push_back('.');
        }
        board.push_back(row);
    }

    findConfig(n_, 0, board, configs);
    return configs;



}