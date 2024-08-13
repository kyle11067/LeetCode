
#include <cmath>
#include <math.h>
//[−2^31, 2^31 − 1]
int divide(int dividend, int divisor) {
    long sum = 0;
    long cur = dividend < 0 ? -(long)dividend : dividend;
    long visor = divisor < 0 ? -(long) divisor: divisor;
    
    while (cur >= visor)
    {
        long temp = visor;
        long mul = 1;
        while (cur >= temp)
        {
            cur -= temp;
            sum += mul;
            mul += mul;
            temp += temp;
        }
    }
    sum = (dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0) ? -sum : sum;

    return (int)std::min((long)2147483647, std::max((long)-2147483648, sum));

    
}
