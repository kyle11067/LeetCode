
#include <string>

int strStr(std::string haystack, std::string needle) {

    if (needle.size() > haystack.size())
    {
        return -1;
    }
    for (size_t i = 0; i < haystack.size() - needle.size() + 1; i++)
    {
        /* code */
        std::string substring = std::string(haystack.begin() + i, haystack.begin() + i + needle.size() );
        if (needle == substring)
        {
            return i;
        }
    }
    


    return -1;
}