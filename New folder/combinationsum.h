#include <vector>
#include <algorithm>
void generateCombination(std::vector<std::vector<int>>& combinations, std::vector<int>& candidates, std::vector<int> & combination, int target);
void generateCombination2(std::vector<std::vector<int>>& combinations, std::vector<int>& candidates, std::vector<int> & combination, int target, int i);

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;
        generateCombination(combinations, candidates, combination, target);
    return combinations;
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;
        generateCombination2(combinations, candidates, combination, target, 0);
    return combinations;
}
void generateCombination2(std::vector<std::vector<int>>& combinations, std::vector<int>& candidates, std::vector<int> & combination, int target, int i)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        std::vector<int> combinationCopy = std::vector<int>(combination);
        
        sort(combinationCopy.begin(),combinationCopy.end());
        if (std::find(combinations.begin(),combinations.end(), combinationCopy) == combinations.end())
        {
            combinations.push_back(combination);
        }
        return;
    }
    
    for ( int c = i; c < candidates.size(); c ++)
    {
        int n = candidates.at(c);
        if (n > target) return;
        combination.push_back(n);
        generateCombination2(combinations,candidates, combination, target - n, c + 1);
        combination.pop_back();
    }
}

void generateCombination(std::vector<std::vector<int>> & combinations, std::vector<int>& candidates, std::vector<int> & combination, int target) 
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        std::vector<int> combinationCopy = std::vector<int>(combination);
        
        sort(combinationCopy.begin(),combinationCopy.end());
        if (std::find(combinations.begin(),combinations.end(), combinationCopy) == combinations.end())
        {
            combinations.push_back(combination);
        }
        return;
    }

    for (int n : candidates)
    {
        if (n > target) return;
        combination.push_back(n);
        generateCombination(combinations, candidates, combination, target - n);
        combination.pop_back();
        
    }


}