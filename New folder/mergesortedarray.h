#include <vector>
#include <algorithm>
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int>::iterator a = nums1.begin();
    std::vector<int>::iterator a_end = nums1.begin() + m;
    std::vector<int>::iterator b = nums2.begin();
    for (std::vector<int>::iterator it = a_end; it != nums1.end();it ++ )
    {
        *it = *b;
        b++;
    }
    std::sort(nums1.begin(), nums1.end());
    

}