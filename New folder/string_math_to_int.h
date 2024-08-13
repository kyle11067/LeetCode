#include <deque>
#include <string>
#include <stack>
#include <algorithm>


long string_to_long(std::string number);

long string_math_to_long(std::string expression)
{
    // 2 * 8 + 4 - 1;

    std::deque<char> operatorDeque;
    std::deque<long> operandDeque;
    std::deque<char> parentheseDeque;
    std::deque<long>::iterator beginningOfExpression = operandDeque.begin();

    for(std::string::iterator strIT = expression.begin(); strIT != expression.end(); strIT++)
    {
        char character;
        if (strIT == expression.end()) break;
        character = *strIT;
        if (character == '*' || character == '/' || character == '+' || character == '-')
        {
            operatorDeque.push_back(character);
        }
        else if ( '0' <= character && character <= '9' )
        {
            std::string number = "";
            while (strIT != expression.end() && '0' <= character && character <= '9' )
            {
                character = *strIT;
                number += character;
                strIT++;
                character = *strIT;
                
            }
            long number_as_int = string_to_long(number);
            operandDeque.push_back(number_as_int);
            strIT--;
        }
        else if (character == '(')
        {
            beginningOfExpression = operandDeque.end();
            parentheseDeque.push_back('(');
        }
        else if (character == ')')
        {
            deque<long>::iterator operandDequeIT = beginningOfExpression;
            for (deque<char>::iterator operatorDequeIT = operatorDeque.begin(); operatorDequeIT != operatorDeque.end(); operatorDequeIT ++)
            {
                if (*operatorDequeIT == '*')
                {
                    long first = *operandDequeIT;
                    long second = operandDequeIT[1];
                    long res = first * second;
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    operandDeque.insert(operandDequeIT, res);
                    operatorDequeIT = operatorDeque.erase(operatorDequeIT);
                    
                }
                else if (*operatorDequeIT == '/')
                {
                    long first = *operandDequeIT;
                    long second = operandDequeIT[1];
                    long res = first / second;
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    operandDeque.insert(operandDequeIT, res);
                    operatorDequeIT = operatorDeque.erase(operatorDequeIT);
                }
                operandDequeIT++;
            }
            while (operandDeque.size() > 1)
            {
                long first = operandDeque.front();
                operandDeque.pop_front();
                long second = operandDeque.front();
                operandDeque.pop_front();
                char operator_ = operatorDeque.front();
                operatorDeque.pop_front();
                long operationResult;
            
                if (operator_ == '+')
                {
                    operationResult = first + second;
                }
                else if (operator_ == '-')
                {
                    operationResult = first - second;
                }
            
                operandDeque.push_front(operationResult);
            }
        }
    }

    deque<long>::iterator operandDequeIT = operandDeque.begin();
            for (deque<char>::iterator operatorDequeIT = operatorDeque.begin(); operatorDequeIT != operatorDeque.end(); operatorDequeIT ++)
            {
                if (*operatorDequeIT == '*')
                {
                    long first = *operandDequeIT;
                    long second = operandDequeIT[1];
                    long res = first * second;
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    operandDeque.insert(operandDequeIT, res);
                    operatorDequeIT = operatorDeque.erase(operatorDequeIT);
                    
                }
                else if (*operatorDequeIT == '/')
                {
                    long first = *operandDequeIT;
                    long second = operandDequeIT[1];
                    long res = first / second;
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    
                    operandDequeIT = operandDeque.erase(operandDequeIT);
                    operandDeque.insert(operandDequeIT, res);
                    operatorDequeIT = operatorDeque.erase(operatorDequeIT);
                    
                }
                
            }
            while (operandDeque.size() > 1)
            {
                long first = operandDeque.front();
                operandDeque.pop_front();
                long second = operandDeque.front();
                operandDeque.pop_front();
                char operator_ = operatorDeque.front();
                operatorDeque.pop_front();
                long operationResult;
            
                if (operator_ == '+')
                {
                    operationResult = first + second;
                }
                else if (operator_ == '-')
                {
                    operationResult = first - second;
                }
            
                operandDeque.push_front(operationResult);
            }

    long finalResult = operandDeque.front();
    return finalResult;

}


long string_to_long(std::string number) 
{
    long n = 0; // number   1234
    for (size_t i = 0; i < number.size(); i++)
    {
        /* code */
        n += (number.at(i) - '0');
        n *= 10;
    }
    n /= 10;
    return n;




}