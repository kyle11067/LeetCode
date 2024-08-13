#include <vector>
#include <algorithm>
std::vector<std::vector<int>> merge_(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](auto &first, auto & second) {return first.at(0) < second.at(0);});
    std::vector<std::vector<int>> mergedIntervals;
    int lower;
    int upper;
    for (std::vector<int> vector : intervals)
    {
       
       if (mergedIntervals.empty())
       {
            lower = vector.at(0);
            upper  = vector.at(1);
            mergedIntervals.push_back(vector);
            continue;
       }

       if (vector.at(0) >= lower && vector.at(1) <= upper)
       {
            continue;
       } else if (vector.at(0) >= lower && vector.at(0) <= upper &&  vector.at(1) > upper)
       {
            std::vector<int> toAdd = std::vector<int>({lower, vector.at(1)});
            upper = vector.at(1);
            mergedIntervals.pop_back();
            mergedIntervals.push_back(toAdd);
       } else
       {
            lower = vector.at(0);
            upper = vector.at(1);
            mergedIntervals.push_back(vector);
       }


    }
    return mergedIntervals;
    
}
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    intervals.push_back(newInterval);
    return merge_(intervals);    

        
}