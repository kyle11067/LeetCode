#include <vector>
#include <math.h>

bool grayCodeHelper(int n, int & num, std::vector<int> & cur, std::vector<int> & seen)
{

    int tot = (int)pow(2, n);
    if (cur.size() == tot)
    {
        return true;
    }
    if (seen.at(num) == 1)
    {
        return false;
    }

    seen.at(num) = 1;
    cur.push_back(num);
    for (int i = 1; i < tot; i <<= 1)
    {
        if ( (num & i) == 0)
        {
            //flip bit
            num += i;
            grayCodeHelper(n , num, cur, seen);
            num -= i;
            // flip bit again
        }
        else
        {
            // flip bit
            num -= i;
            grayCodeHelper(n,num,cur,seen);
            num += i;
            // flip bit again
        }
    }
    return true;
}

std::vector<int> grayCode(int n) {
    int tot = (int) pow(2,n);
    int num = 0;
    std::vector<int> seen = std::vector<int>(tot, 0);
    std::vector<int>  cur = {};
    grayCodeHelper(n, num, cur, seen );
    return cur;

}