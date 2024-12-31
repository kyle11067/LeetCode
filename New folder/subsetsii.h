#include <vector>
#include <algorithm>
void sets(std::vector<int> & nums, std::vector<int> & set, std::vector<std::vector<int>> & subsets)
{
    if (find(subsets.begin(), subsets.end(), set) != subsets.end())
    {
        return;
    }
    subsets.push_back(set);
    for (int i = 0;i < nums.size(); i ++)
    {
        set.push_back(nums.at(i));
        std::vector<int> slicedNums(nums.begin() + i + 1, nums.end());
        sets(slicedNums, set, subsets);
        set.pop_back();
    }
}


std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> subsets;
        std::vector<int> set;
        sets(nums, set, subsets);
        return subsets;

    }