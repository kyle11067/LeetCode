#include <vector>
#include <map>
#include <set>
#include <algorithm>

int row_col_to_square(int r, int c);

bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::map<int,std::vector<char>> row_set;
        std::map<int,std::vector<char>> column_set;
        std::map<int,std::vector<char>> square_set; // must be 0-8

        for (int i = 0; i < 9; i ++ )
        {
            row_set.insert(std::pair<int, std::vector<char>>({i, {} }));
            column_set.insert(std::pair<int, std::vector<char>>({i, {} }));
            square_set.insert(std::pair<int, std::vector<char>>({i, {} }));
        }


        // element to
        for (std::size_t row = 0; row < board.size(); row++)
        {
            /* code */
            for (std::size_t column = 0; column < board.at(0).size(); column++)
            {
                /* code */
                char el = board.at(row).at(column);
                if (el == '.') continue;
                std::vector<char> & row_vector = row_set.at(row);
                std::vector<char> & column_vector = column_set.at(column);
                int square_idx = row_col_to_square(row,column);
                std::vector<char> & square_vector = square_set.at(square_idx);
                if (std::find(row_vector.begin(), row_vector.end(), el ) != row_vector.end() ||
                     std::find(column_vector.begin(), column_vector.end(), el ) != column_vector.end() ||
                      std::find(square_vector.begin(), square_vector.end(), el ) != square_vector.end())
                {
                    return false;
                }
                else
                {
                    row_set.at(row).push_back(el);
                    column_set.at(column).push_back(el);
                    square_set.at(square_idx).push_back(el);
                }

            }
            
        }
        return true;

}


int row_col_to_square(int r, int c)
{
    if ( r >= 0 && r <= 2)
    {
        return c  / 3;
    } else if (r >= 3 && r <= 5)
    {
        return 3 + (c / 3);
    }
    else {
        return 6 + (c / 3);
    }
}