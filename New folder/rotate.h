#include <vector>
#include <algorithm>
void rotate(std::vector<std::vector<int>>& matrix) {
        
        int temp = matrix.at(0).at(0);
        int  n = matrix.size();
        int start  = 0;
        int end = n -1; int offset = 0;
        // loop 1 , squares
        for ( n = matrix.size(); n > 1; n -= 2   )    


        {
            end = n-1;
            for (int k = start; k < start + end; k ++) // loop 2 , indices to < n - 1
            {
                
                temp = matrix.at(start).at(k);
                    
                
                std::swap(matrix.at(k).at(start + end) , temp);
                std::swap(matrix.at(start + end).at(start + end-k + start), temp);
                std::swap(matrix.at(start + end-k + start).at(start), temp);
                matrix.at(start).at(k) = temp;
            }
            start += 1;
            
        }
    }