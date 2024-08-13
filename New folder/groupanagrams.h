#include <vector>
#include <string>
#include <map>
#include <algorithm>
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        int counter = 0;
        std::map<std::string , int> sortedStringToIndex ;
        std::vector<std::vector<std::string>> anagrams;
        for (std::string str: strs)
        {
            std::string copy = str;
            sort(copy.begin(), copy.end());
            if (sortedStringToIndex.find(copy) == sortedStringToIndex.end())
            {
                sortedStringToIndex.insert({copy, counter++});
                anagrams.push_back({str});
            }
            else
            {
                anagrams.at(sortedStringToIndex.at(copy)).push_back(str);
            }

        }


        

        return anagrams;
    }