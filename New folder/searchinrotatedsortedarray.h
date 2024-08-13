
#include <vector>

int search(std::vector<int>& nums, int target) {
    if (nums.size() == 1)
    {
        if (nums.at(0) == target)
        {
            return 0;
        } else
        {
            return -1;
        }
    }

    if (nums.size() == 2)
    {
        if (nums.at(0) == target) return 0;
        else if (nums.at(1) == target) return 1;
        else return -1;
    }

    // left side
    int mid = nums.size() / 2;
    if (nums.at(mid) == target)
    {
        return mid;
    }
    else if (nums.at(mid) > target)
    {
        std::vector<int> slicedVector = std::vector<int>(nums.begin() , nums.begin() + mid );
        int try_ = search(slicedVector, target);
        if (try_ == -1)
        {
            std::vector<int> slicedVectorUpper = std::vector<int>(nums.begin() + mid + 1, nums.end());
            try_ = search(slicedVectorUpper, target);
            return (try_ == -1)? try_ : try_ + mid + 1;
        }
        else
        {
            return try_;
        }

    } else 
    {
        std::vector<int>slicedVector = std::vector<int>(nums.begin() + mid + 1, nums.end());
        int try_ = search(slicedVector,target);
        if (try_ == -1)
        {
            std::vector<int> slicedVectorLower = std::vector<int>(nums.begin(), nums.begin() + mid);
            try_ = search(slicedVectorLower,target);
            return try_;
        }else
        {
            return try_ + mid + 1;
        }

    }


}