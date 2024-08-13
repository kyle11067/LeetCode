#include <vector>
#include <string>
#include <algorithm>
void nextPermutationHelper(std::vector<int> & nums, size_t left, size_t right);

 void nextPermutation(std::vector<int>& nums) {
    if (nums.size() == 1 || nums.size() == 0)
    {
        return;
    }
    if (nums.size() == 2)
    {
        std::swap(nums.at(0),nums.at(1));
        return;
    }
    std::size_t right = nums.size() - 1;
    std::size_t left = right - 1;
    nextPermutationHelper(nums, left, right);
}


void nextPermutationHelper(std::vector<int> & nums, size_t left, size_t right)
{
    if (nums.at(left) < nums.at(right))
    {
        int lower_bound_index = right;
        while (right < nums.size())
        {
            if (nums.at(right) > nums.at(left) && nums.at(right) < nums.at(lower_bound_index))
            {
                lower_bound_index = right;
                
            }
            right ++;
           
        }
        std::swap(nums.at(left), nums.at(lower_bound_index));
        sort(nums.begin() + left + 1, nums.end());
        return;
    }
    else if (left == right - 1 && left > 0)
    {
        nextPermutationHelper(nums, left - 1, right);
    } else if ( left < right - 1)
    {
        nextPermutationHelper(nums, left, right - 1);
    }
    else{
        sort(nums.begin(), nums.end());
    }

}