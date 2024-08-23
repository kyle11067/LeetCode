#include<vector>

void sortColors(std::vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return;
        if (nums.size() == 2) {
            if (nums.at(0) > nums.at(1))
            {
                std::swap(nums.at(0), nums.at(1));
                return;
            }
        }
        // std::vector<int> & firstHalf = std::vector<int> (nums.begin(), nums.begin() + nums.size() / 2);
        // std::vector<int> & 
    std::vector<int>::iterator two_tracker = nums.begin();
    std::vector<int>::iterator zero_tracker = nums.end() - 1;
    int two_tracker_target = 0;
    int zero_tracker_target = 2;
    while(two_tracker < zero_tracker)
    {
        while (0 < zero_tracker - two_tracker && *two_tracker == two_tracker_target)
        {
            two_tracker++;
        }
        while (zero_tracker - two_tracker > 0 && *zero_tracker == zero_tracker_target)
        {
            zero_tracker--;
        }

        if (*two_tracker == 1 && *zero_tracker == 1)
        {
            break;
        }
        std::swap(*two_tracker, *zero_tracker);
    }

    std::vector<int>::iterator ones_tracker = two_tracker + 1;
    while (ones_tracker <= zero_tracker)
    {
        if (*ones_tracker == 2 && *zero_tracker == 2) 
        {
            zero_tracker --;
            continue;
        }
        if (*ones_tracker == 0 && *two_tracker == 0)
        {
            two_tracker++;
            continue;
        }

        if (*ones_tracker == 0)
        {
            std::swap(*ones_tracker, *two_tracker);
            two_tracker++;
            if (*ones_tracker == 2)
            {
                std::swap(*ones_tracker, *zero_tracker);
                zero_tracker--;    
            }
        } else if (*ones_tracker == 2)
        {
            std::swap(*ones_tracker, *zero_tracker);
            zero_tracker--;
            if (*ones_tracker == 0)
            {
                std::swap(*ones_tracker, *two_tracker);
                two_tracker++;
            }
            
        }
        ones_tracker++;
    }
   
        
}