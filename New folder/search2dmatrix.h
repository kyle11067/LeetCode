#include <vector>




bool searchRow (std::vector<int> & row, int target)
{
    if (row.size() == 0) return false;
    if (row.size() == 1) return row.at(0) == target;
    int m = row.size() / 2;
    if (row.at(m) == target) return true;
    else if (target < row.at(m))
    {
        std::vector<int> slicedVector = std::vector<int>(row.begin(), row.begin() + m);
        return searchRow(slicedVector, target);
    } else 
    {
        std::vector<int> slicedVector = std::vector<int>(row.begin() + m + 1, row.end());
        return searchRow(slicedVector, target);    
    }


}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;
    if (matrix.size() == 1) return searchRow(matrix.at(0), target);
    int m = matrix.size();
    int n = matrix.at(0).size();


    std::vector<int> middleRow = matrix.at(m / 2);
    if (target < middleRow.at(0))
    {
        std::vector<std::vector<int>> slicedMatrix = std::vector<std::vector<int>>(matrix.begin(), matrix.begin() + m / 2);
        return searchMatrix(slicedMatrix, target);
    } else if (target > middleRow.at(n-1))
    {
        std::vector<std::vector<int>> slicedMatrix = std::vector<std::vector<int>>(matrix.begin() + (m/2) + 1, matrix.end());
        return searchMatrix(slicedMatrix, target);
    } else
    {
        return searchRow(middleRow, target);
    }


}