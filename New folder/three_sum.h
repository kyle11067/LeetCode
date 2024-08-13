#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


vector<vector<int>> newtwoSum(vector<int>& nums, int target) {
        vector<vector<int>> indices;
        map<int, int> numToIndex;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {   
            vector<int> tempVector;
            if (numToIndex.find( target - *it )  != numToIndex.end())
            {
                tempVector.push_back(it - nums.begin());
                tempVector.push_back(numToIndex.at(target - *it));
                indices.push_back(tempVector);
            }
            numToIndex.insert(std::pair<int, int>({*it, it - nums.begin()}  ) );
           
        }
        return indices;


}
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end()); // sort
        for (size_t i = 0; i < nums.size(); i++)
        {
        
            int cur_num = nums.at(i);
            int l = i + 1;
            int r = nums.size() - 1;
            if (i > 0 && cur_num == nums[i - 1])
            {
                continue;
            }
            while ( l < r)
            {
                int sum_ = cur_num + nums.at(l) + nums.at(r);
                if (sum_ > 0)
                {
                    r -= 1;
                } else if (sum_ < 0)
                {
                    l += 1;
                }
                else
                {
                    vector<int> triplet = {cur_num, nums.at(l),nums.at(r)};
                    triplets.push_back(triplet);
                    l += 1;
                    while (l < r && nums.at(l) == nums.at(l-1))
                    {
                        l += 1;
                    }
                }
            }
            
        }
        return triplets;
    }