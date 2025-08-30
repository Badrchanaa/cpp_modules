#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        return 0;
    try
    {
        long res = RPN(av[1]);
        std::cout << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}