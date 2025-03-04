#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap *ct;
    DiamondTrap dt("test");

    std::cout << " --------- MAIN START ----------" << std::endl;
    dt.whoAmI();
    dt.attack("test");
    ct = &dt;
    ct->attack("test");
    std::cout << " --------- MAIN END ----------" << std::endl;
    return 0;
}