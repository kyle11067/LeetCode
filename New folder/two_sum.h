#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        map<int, int> numToIndex;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
             if (numToIndex.find( target - *it )  != numToIndex.end())
            {
                indices.push_back(it - nums.begin());
                indices.push_back(numToIndex.at(target - *it));
                return indices;
            }
            numToIndex.insert(std::pair<int, int>({*it, it - nums.begin()}  ) );
           
        }
        return indices;


}