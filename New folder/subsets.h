#include <vector>

void combineHelper( int n, int k, int i, std::vector<int> & combo, std::vector<std::vector<int>> & combinations, std::vector<int> & origVector) {
    if (combo.size() == k)
    {
        combinations.push_back(std::vector<int>(combo));
        return;
    }
    for (int x = i; x< n; x++)
    {
        combo.push_back(origVector.at(x));
        combineHelper(n,k, x+1, combo, combinations,origVector);
        combo.pop_back();
    }

}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> sets;
       
        std::vector<int> combo;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            combineHelper(n, i, 0, combo, sets, nums);
        }
        sets.push_back(nums);

    return sets;



    }