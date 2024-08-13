#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> modifiedthreeSum(std::vector<int> & nums, int target);
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
{
    std::vector<std::vector<int>> quadruplets;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i <nums.size(); i ++)
    {
        
        int cur_num = nums.at(i);
        if (i > 0 && cur_num == nums[i-1])
        {
            continue;
        }
        std::vector<int> slicedVector = std::vector<int>(nums.begin() + 1, nums.end());
        std::vector<std::vector<int>> triplets = modifiedthreeSum(slicedVector, target - cur_num);
        for (std::vector<int> triplet: triplets)
        {
            quadruplets.push_back(std::vector<int>({cur_num, triplet.at(0), triplet.at(1),triplet.at(2)}));
        }

    }
    return quadruplets;

}

std::vector<std::vector<int>> modifiedthreeSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> triplets;
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
                if (sum_ > target)
                {
                    r -= 1;
                } else if (sum_ < target)
                {
                    l += 1;
                }
                else
                {
                    std::vector<int> triplet = {cur_num, nums.at(l),nums.at(r)};
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