#include <vector>
#include <cmath>
#include <climits>
int jump(std::vector<int>& nums) {
    if (nums.size() == 1)
    {
        return 0;
    }
    if (nums.size() == 2)
    {
        return (nums.at(0) > 0)? 1 : 0;
    }
    long jumptable[nums.size()];
    jumptable[0] = 0;
    for (int i = 1; i < nums.size(); i ++)
    {
        if ( abs(i) <= nums[0])
        {
            jumptable[i] = 1;
        } else
        {
            jumptable[i] = INT_MAX;
            for (int k = 1; k < i; k ++)
            {
                if (abs(k - i) <= nums[k])
                {
                    jumptable[i] = std::min(jumptable[i], 1 + jumptable[k]);
                }
            }
        }
    }



    return jumptable[nums.size() - 1];



}