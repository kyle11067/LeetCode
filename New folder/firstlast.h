#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if (nums.size() == 0) return {-1,-1};
    
    if (nums.size() == 1)
    {
        if (nums.at(0) == target)
        {
            return {0,0};
        }
        else return {-1,-1};
    }

    if (nums.size() == 2)
    {   
        if (nums.at(0) == target && nums.at(1) != target)
        {
            return {0,0};
        } 
        else if (nums.at(0) != target && nums.at(1) == target)
        {
            return {1,1};
        } 
        else if (nums.at(0) == target && nums.at(1) == target)
        {
            return {0,1};
        }
        else 
        {
            return {-1,-1};
        }
    }


    int mid = nums.size() / 2;
    if (target < nums.at(mid))
    {   
        std::vector<int> slicedVector = std::vector<int>(nums.begin(), nums.begin() + mid);
        return searchRange(slicedVector, target);
    }
    else if (target > nums.at(mid))
    {
        std::vector<int> slicedVector = std::vector<int>(nums.begin() + mid + 1, nums.end());
        std::vector<int> bounds = searchRange(slicedVector,target);
        if (bounds.at(0) == -1 && bounds.at(1) == -1) return bounds;
        return {mid + 1 + bounds.at(0), mid + 1 + bounds.at(1)};
    }
    else
    {
        int low;
        int high;
        std::vector<int> slicedVectorLower = std::vector<int>(nums.begin(), nums.begin() + mid);
        std::vector<int> slicedVectorUpper = std::vector<int>(nums.begin() + mid + 1, nums.end());
        if (mid == 0 || (mid != 0 && nums.at(mid - 1) != target))
        {
            low = mid;
            std::vector<int> upperBounds = searchRange(slicedVectorUpper, target);
            high = upperBounds.at(1) + mid + 1;
        }
        else if (mid == nums.size() - 1 || (mid != nums.size() && nums.at(mid + 1) != target))
        {
            high = mid;
            std::vector<int> lowerBounds = searchRange(slicedVectorLower, target);
            low = lowerBounds.at(0);    
        }else
        {
            std::vector<int> upperBounds = searchRange(slicedVectorUpper, target);
            high = upperBounds.at(1) + mid + 1;
            std::vector<int> lowerBounds = searchRange(slicedVectorLower, target);
            low = lowerBounds.at(0); 
        }
        

        
        

        return {low,high};
    }
        
}