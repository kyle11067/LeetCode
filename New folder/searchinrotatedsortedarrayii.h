#include <vector>

bool search(std::vector<int>& nums, int target) {
    if (nums.size() == 0) return false;
    if (nums.size() == 1)
    {
        if (nums.at(0) == target ) return true;
        else return false;
    }

    int mid = nums.size() / 2;

    int val = nums.at(mid);
    if (val == target) return true;
    std::vector<int> slicedUpper = std::vector<int>(nums.begin() + mid + 1, nums.end());
    std::vector<int> slicedLower = std::vector<int>(nums.begin(), nums.begin() + mid);
    if (val < target)
    {
        if (search(slicedUpper,target))
        {
            return true;
        }
        return search(slicedLower, target);
    }
    else if (val > target)
    {
        if (search(slicedLower,target))
        {
            return true;
        }
        return search(slicedUpper,target);
    }

    return false;

}