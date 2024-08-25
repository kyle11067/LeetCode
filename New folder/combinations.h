#include <vector>

void combineHelper( int n, int k, int i, std::vector<int> & combo, std::vector<std::vector<int>> & combinations) {
    if (combo.size() == k)
    {
        combinations.push_back(std::vector<int>(combo));
        return;
    }
    for (int x = i; x<= n; x++)
    {
        combo.push_back(x);
        combineHelper(n,k, x+1, combo, combinations);
        combo.pop_back();
    }

}


 std::vector<std::vector<int>> combine(int n, int k) {
        
        std::vector<std::vector<int>> combinations;
        std::vector<int> combo;
        if (k == 1)
        {
            for (int i = 1; i <= n;i++)
            {
                combinations.push_back({i});
            }
            return combinations;
        }
        
        combineHelper(n, k, 1, combo, combinations);
        return combinations;
}