#include <string>
#include <stack>
std::string simplifyPath(std::string path) {
    std::string simplifiedPath = "";
    std::string sampleString;
    std::stack<std::string> words;        
    std::string::iterator it;
    if (path.at(path.size() - 1) != '/')
    {
        path.push_back('/');
    }
    for ( it = path.begin(); it != path.end(); it++)
    {
        if (*it == '/')
        {
            if (!sampleString.empty())
            {
                if (sampleString == ".")
                {
                    sampleString = "";
                } else if (sampleString == "..")
                {
                    if (!words.empty())
                    {
                        words.pop();
                    }
                    sampleString = "";
                } else
                {
                    words.push(sampleString);
                    sampleString = "";
                }
            }
        }
        else
        {
            sampleString.push_back(*it);
        }
    }
    
    if (words.empty())
    {
        return "/";
    }
    while (!words.empty())
    {
        std::string toInsert = words.top();
        simplifiedPath = "/" + toInsert + simplifiedPath;
        words.pop();
    }
    return simplifiedPath;

}