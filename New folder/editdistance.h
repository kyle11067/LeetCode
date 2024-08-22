#include <string>
#include <algorithm>
int minDistance(std::string word1, std::string word2) {
    int distance  [1 + word1.size()][1 + word2.size()];

    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    for (int i = 0; i <= word1.size(); i ++)
    {
        distance[i][0] = i;
    }
    for (int i = 0; i <= word2.size(); i++)
    {
        distance[0][i] = i;
    }

    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j ++)
        {
            if (word1.at(i-1) == word2.at(j-1))
            {
                distance[i][j] = std::min(std::min(distance[i-1][j-1], 1 + distance[i-1][j]), 1 + distance[i][j-1] );
            } else
            {
                distance[i][j] = std::min(std::min(1 + distance[i-1][j-1],1 + distance[i-1][j]), 1 + distance[i][j-1] );
            }
        }
    }


    return distance[word1.size()][word2.size()];

}

