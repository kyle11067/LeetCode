#include <string>
#include <map>
std::string countAndSay(int n) {
    static std::string nToString [31] = 
    {"", "", "", "" ,"",
    "", "", "", "" ,"",
    "", "", "", "" ,"",
    "", "", "", "" ,"", 
    "", "", "", "" ,"",
    "", "", "", "" ,"", ""};
    std::map<char, int> characterCount;

    
    if (n == 1){
        nToString[1] == "1";
        return "1";
            
    }

    
    if (nToString[n] != "")
    {
        return nToString[n];
    }

    
    std::string before = nToString[n-1];
    if (before == "") before = countAndSay(n - 1);
    std::string modifiedString;
    char cur_char = before.at(0);
    characterCount.insert({cur_char, 0});
    for (size_t i = 0; i < before.size(); i ++)
    {
        if (before.at(i) == cur_char)
        {
            characterCount.at(cur_char) += 1;
        }else
        {
            // done with cur_char
            modifiedString.push_back('0' + characterCount.at(cur_char));
            modifiedString.push_back(cur_char);
            characterCount.at(cur_char) = 0;
            cur_char = before.at(i);
            if (characterCount.find(cur_char) == characterCount.end())
            {
                characterCount.insert({cur_char, 1});
            }else
            {
                characterCount.at(cur_char) = 1;
            }
            
            
        }
        
    }
    modifiedString.push_back('0' + characterCount.at(cur_char));
    modifiedString.push_back(cur_char);
    nToString[n] = modifiedString;
    return modifiedString;
}