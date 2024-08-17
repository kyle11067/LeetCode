#include <string>
#include <cmath>
std::string addBinary(std::string a, std::string b) {
        char A;
        char B;
        char cin = '0';
        char cout = '0';
        char s;

        std::string::iterator bIt = b.end() - 1;
        std::string::iterator aIt = a.end() - 1;
        if (a.size() < b.size())
        {
            while (a.size() < b.size())
            {
                a.insert(a.begin(),'0');
            }
        } else if (b.size() < a.size())
        {
            while (b.size() < a.size())
            {
                b.insert(b.begin(), '0');
            }
        }
        bIt = b.end() - 1;
        aIt = a.end() - 1;
        if (b == "0" && a == "0")
        {
            return "0";
        }
        std::string result;
        for (int i = (int)fmax(a.size() - 1, b.size() - 1); i >= 0 ; i --)
        {
            
            cin = cout;
            B = *bIt;
            A = *aIt;

            
            cout = ( (B == '1' && A == '1') ||
                    (cin == '1' && A == '1') ||
                    (cin == '1' && B == '1') ) ? '1' : '0';
            s =  ( (B == '1' && A == '0' && cin == '0')  ||
                    (B == '0' && A == '1' && cin == '0') ||
                    (B == '0' && A == '0' && cin == '1') ||
                    (B == '1' && A == '1' && cin == '1')
                    ) ? '1' : '0';
                    result.insert(result.begin(), s);
            bIt --;
            aIt --;
        }
        if (cout == '1'){
            result.insert(result.begin(),'1');
        } else if (*result.begin() == '0')
        {
            result.erase(result.begin());
        }



        return result;
    }