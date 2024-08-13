#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2) {
     static const std::vector<std::vector<int>> multiplicationTable = { {0, 0, 0, 0,0, 0, 0, 0, 0, 0},
                                                                                {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                                                                                {0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
                                                                                {0, 3, 6, 9, 12, 15, 18, 21, 24, 27},                                                                             
                                                                                {0, 4, 8, 12, 16, 20, 24, 28, 32, 36}, 
                                                                                {0, 5, 10, 15, 20, 25, 30, 35, 40, 45},
                                                                                {0, 6, 12, 18, 24, 30, 36, 42, 48, 54},
                                                                                {0, 7, 14, 21, 28, 35, 42, 49, 56, 63},
                                                                                {0, 8, 16, 24, 32, 40, 48, 56, 64, 72},
                                                                                {0, 9, 18, 27, 36, 45, 54, 63, 72, 81}                                                                                                                                                        
      };
      if (num1 == "0" || num2 == "0")return "0";

      int product [num1.size() + num2.size()];
      for (int i = 0; i < num1.size() + num2.size() ; i ++ )
      {
            product[i] = 0;
      }
      for (size_t i = 0; i < num1.length(); i ++)
      {
            for (size_t j = 0;  j  < num2.size(); j ++)
            {
                  int num_zeros = i  + j;
                  int first = num1.at(num1.length() - 1 - i) - '0';
                  int second = num2.at(num2.length() - 1 - j) - '0';
                  int temp_product = multiplicationTable.at(first).at(second);
                  int productIterator;
                  for (productIterator = num1.size() + num2.size() - 1; productIterator >= 0; productIterator --)
                  {
                        if (num_zeros > 0)
                        {
                              num_zeros--;
                              continue;
                        }
                        if (temp_product > 0)
                        {
                              int part = temp_product % 10;
                              product[productIterator] += part;
                              temp_product /= 10;
                              if (product[productIterator] >= 10)
                              {
                                    product[productIterator] -= 10;
                                    temp_product += 1;
                                    
                              }
                              continue;
                        }
                        break;
                  }



            }
      }
      std::string prod= "";
      for (int i = 0; i < num1.size() + num2.size(); i++)
      {
            if (product[i] == 0 && prod.size() == 0) continue;
            prod.push_back('0' + product[i]);
      }
      return prod;


}