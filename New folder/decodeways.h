#include <string>

bool isValid(std::string s)
{
    if (s == "1" ||
        s == "2" ||
        s == "3" ||
        s == "4" ||
        s == "5" ||
        s == "6" ||
        s == "7" ||
        s == "8" ||
        s == "9" ||
        s == "10" ||
        s == "11" ||
        s == "12" ||
        s == "13" ||
        s == "14" ||
        s == "15" ||
        s == "16" ||
        s == "17" ||
        s == "18" ||
        s == "19" ||
        s == "20" ||
        s == "21" ||
        s == "22" ||
        s == "23" ||
        s == "24" ||
        s == "25" ||
        s == "26" 
        )
    {
        return true;
    }
    return false;
}

void findNumDecodings(std::string & s, int & num)
{
    if (s.size() == 0) 
    {
        num++;
        return;
    }
    
    std::string lowerOne = std::string(s.begin(), s.begin() + 1);
    if (isValid(lowerOne))
    {
        std::string upper = std::string(s.begin() + 1, s.end());
        findNumDecodings(upper, num);
    }
    if  (s.size() >= 2)
    {
        std::string lowerTwo = std::string(s.begin(), s.begin() + 2);
        if (isValid(lowerTwo))
        {
            std::string upper = std::string(s.begin() + 2, s.end());
            findNumDecodings(upper,num);
        }
    }

        

    
}

int numDecodings(std::string s) {
    std::string s_ = s;
    int num = 0;
    int t[s.size() + 1];
    t[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (i == s.size() - 1)
        {
            if (isValid(std::string(s_.begin() + i, s_.begin() + i + 1)) )
            {
                t[i] = 1;
                continue;
            }
        
            else
            {
                t[i] = 0;
                continue;
            }
        }
        if (i == s.size() - 2)
        {
            std::string one(s.begin() + i, s.begin() + i + 1);
            std::string two(s.begin() + i, s.begin() + i + 2);
            t[i] = (isValid(one) ? t[i+1] : 0) + (isValid(two) ?  t[i+2] : 0) + (isValid(one) && isValid(two) ? 1 : 0);
            continue; 
        }
        std::string one(s.begin() + i, s.begin() + i + 1);
        std::string two(s.begin() +i, s.begin() + i + 2);
        t[i] = (isValid(one) ? t[i+1] : 0) +  (isValid(two) ?  t[i+2] : 0); 
    }
    return t[0];


}