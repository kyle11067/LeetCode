#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> number = std::vector<int>(digits);
        int carry = number.at(number.size() - 1) + 1;
        std::vector<int>::iterator end = number.end() - 1;
        while (carry == 10)
        {
            if (end == number.begin())
            {
                *end = 0;
                number.insert(number.begin(), 0);
                end = number.begin();
                break;
            }
            *end = 0;
            end --;
            carry = *end + 1;
        }
        *end += 1;


        return number;

    }