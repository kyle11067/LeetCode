#include <vector>
#include <cmath>
int maxSubArray(std::vector<int>& nums) {
        
        int maxsum = 0x8fff0000;
        int cursum = nums.at(0);
        for (int i = 0; i < nums.size(); i ++)
        {
            cursum += nums.at(i);
            if (cursum < 0)
            {
                cursum = 0;
            }
            maxsum = cursum > maxsum ? cursum : maxsum;


        }
        return maxsum;
    }
