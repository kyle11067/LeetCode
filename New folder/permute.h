#include <vector>
#include <algorithm>
#include <map>
void permuteHelper(std::vector<int> & nums, std::vector<std::vector<int>> & permutations, int j);

void permuteUniqueHelper(std::vector<int> & permutation, std::vector<std::vector<int>> & permutations, std::map<int,int> & num_count, int size);


std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;
    permuteHelper(nums, permutations,0);
    return permutations;
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::map<int, int> num_count;
    for (int n: nums)
    {
        if (num_count.find(n) == num_count.end())
        {
            num_count.insert(std::pair<int,int>({n, 1}));
        }
        else
        {
            num_count.at(n) += 1;
        }
    }

    std::vector<int> permutation;
        std::vector<std::vector<int>> permutations;
    permuteUniqueHelper(permutation, permutations,num_count, nums.size());
    return permutations;
    }


void permuteUniqueHelper(std::vector<int> & permutation, std::vector<std::vector<int>> & permutations, std::map<int,int> & num_count, int size)
{
    
    for (std::map<int,int>::iterator it = num_count.begin(); it != num_count.end(); it ++)
    {
        if (it->second > 0)
        {
            permutation.push_back(it->first);
            it->second -= 1;
            permuteUniqueHelper(permutation,permutations,num_count, size);
            it->second += 1;
            permutation.pop_back();
        }
    }
    if (permutation.size() == size)
        permutations.push_back(permutation);

}
void permuteHelper(std::vector<int> & nums, std::vector<std::vector<int>> & permutations, int j)
{
    if (j == nums.size())
    {
        permutations.push_back(nums);
        
    }
    for (int i = j; i < nums.size(); i ++)
    {
        std::swap(nums.at(i), nums.at(j));        
        permuteHelper(nums, permutations, j + 1);
        std::swap(nums.at(i),nums.at(j));
    }
}