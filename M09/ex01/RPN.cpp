#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <queue>
#include <stack>

static long    calc_expression(long a, long b, char op)
{
    switch(op)
    {
        case '-':
            return a - b;
        case '+':
            return a + b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            throw std::exception();
    }
}

long RPN(std::string expression)
{
    std::stack<long> q;
    char current;
    std::istringstream iss(expression);
    while ((iss >> current))
    {
        if (current >= '0' && current <= '9')
            q.push(current - '0');
        else
        {
            if (q.size() < 2)
                throw std::exception();
            long a = q.top();
            q.pop();
            long b = q.top();
            q.pop();
            q.push(calc_expression(b, a, current));
        }
    }
    if (q.size() != 1)
        throw std::exception();
    return q.top();
}