#include <vector>
#include <string>


bool existHelper(std::vector<std::vector<char>>& board, std::string word, int i, int j, std::vector<std::vector<int>> & filled)
{
    if (word.size() == 0) return true;
    if (i >= board.size()) return false;
    if (j >= board.at(0).size()) return false;
    if (i < 0) return false;
    if (j < 0 ) return false;
    if (filled.at(i).at(j)) return false;
    char cur = word.at(0);
    if (board.at(i).at(j) == cur)
    {
        filled.at(i).at(j) = 1;
        if ( !existHelper(board, std::string(word.begin() + 1, word.end()), i + 1 ,j, filled) && !existHelper(board, std::string(word.begin() + 1, word.end()), i ,1 + j,filled) && !existHelper(board, std::string(word.begin() + 1, word.end()), i - 1 ,j,filled) && !existHelper(board, std::string(word.begin() + 1, word.end()), i , j - 1,filled))
        {
            filled.at(i).at(j) = 0;
            return false;
        } else
        {
            return true;
        }

    } else
    {
        return false;
    }

}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    std::vector<std::vector<int>> filled;
    for (int i = 0; i < board.size();i++)
    {   
        std::vector<int> known;
        for (int j = 0; j < board.at(0).size(); j++)
        {
            known.push_back(0);
        }
        filled.push_back(known);
    }
    for (int i = 0; i < board.size();i++)
    {
        for (int j = 0; j < board.at(0).size(); j++)
        {
            if (existHelper(board,word,i,j,filled)) return true;
        }
    }
    return false;

}