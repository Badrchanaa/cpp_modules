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
            throw std::runtime_error("Invalid operator");
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
            if ((current == '/') && a == 0)
                throw std::runtime_error("Division by zero");
            long result = calc_expression(b, a, current);
            q.push(result);
        }
    }
    if (q.size() != 1)
        throw std::runtime_error("Invalid expression");
    return q.top();
}