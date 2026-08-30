#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cctype>

class RPN
{
    private:
        std::stack<long> data;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string &numbers);
};

#endif