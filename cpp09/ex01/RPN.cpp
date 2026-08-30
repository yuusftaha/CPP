#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &other)
{
    this->data = other.data;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->data = other.data;
    return *this;
}

RPN::~RPN()
{

}

void RPN::calculate(const std::string &numbers)
{
    for (size_t i = 0; i < numbers.length(); i++)
    {
        if (isspace(numbers[i]))
            continue;

        if (isdigit(numbers[i]))
        {
            if (i + 1 < numbers.length() && numbers[i + 1] != ' ')
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            data.push(numbers[i] - '0');
        }
        else
        {
            if (data.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }

            int right = data.top();
            data.pop();
            int left = data.top();
            data.pop();

            switch (numbers[i])
            {
                case '+':
                    data.push(left + right);
                    break;
                case '-':
                    data.push(left - right);
                    break;
                case '*':
                    data.push(left * right);
                    break;
                case '/':
                    if (right == 0)
                    {
                        std::cerr << "Error" << std::endl;
                        return;
                    }
                    data.push(left / right);
                    break;
                default:
                    std::cerr << "Error" << std::endl;
                    return;
            }
        }
    }
    if (data.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << data.top() << std::endl;
}