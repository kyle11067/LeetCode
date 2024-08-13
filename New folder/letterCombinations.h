#include <string>
#include <vector>
#include <map>
std::vector<std::string> letterCombinations(std::string digits) {
    
    std::map<std::string, std::vector<std::string>> digit_to_letter;
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"2", {"a","b","c"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"3", {"d","e","f"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"4", {"g","h","i"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"5", {"j","k","l"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"6", {"m","n","o"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"7", {"p","q","r","s"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"8", {"t","u","v"}}));
    digit_to_letter.insert(std::pair<std::string, std::vector<std::string>>({"9", {"w","x","y","z"}}));
    if (digits == "")
    {
        return std::vector<std::string>();
    }

    if (digits.size() == 1)
    {
        return digit_to_letter.at(digits);
    }
    
    std::vector<std::string> subletters = letterCombinations(std::string(digits.begin() + 1, digits.end())  );
    std::vector<std::string> letters = digit_to_letter.at(std::string(digits.begin(), digits.begin() +1));
    
    std::vector<std::string> finalVector;
    for (std::string letter: letters)
    {
        for (std::string combos: subletters)
        {
            finalVector.push_back(letter + combos);
        }
    }
    return finalVector;


}
