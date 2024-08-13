#include <vector>

bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        bool isJump [n];
        isJump[0] = true;
        if (nums.size() == 1) return true;

        if (nums.size() == 2 && nums.at(0) >= 1) return true;

        if (nums.at(0) == 0) return false;

        for (int i = 0; i < n; i ++)
        {
            if (i <= nums.at(0))
            {
                isJump[i] = true;
            } 
            else
            {
                bool foundJump = false;
                for (int k = i - 1; k > 0; k --)
                {
                    if (i - k <= nums.at(k) && isJump[k])
                    {
                        foundJump = true;
                        break;
                    }
                }
                isJump[i] = foundJump;
            }
        }
        return isJump[n-1];
}