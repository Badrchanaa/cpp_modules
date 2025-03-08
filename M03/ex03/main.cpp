#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap x("someone");

    // ScavTrap cp(dt);
    std::cout << " --------- MAIN START ----------" << std::endl;
    x.whoAmI();
    x.attack("dt");
    x.beRepaired(20);
    x.guardGate();
    x.highFivesGuys();
    x.takeDamage(1000);
    x.attack("should not attack");
    std::cout << " --------- MAIN END ----------" << std::endl;
    return 0;
}