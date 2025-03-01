#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap khabib("The eagle");
    FragTrap conor("mcchicken");

    std::cout << "------------- MAIN START --------------" << std::endl;
    conor.attack("The eagle");
    khabib.takeDamage(conor.getAttackDamage());
    khabib.attack("mcchicken");
    conor.takeDamage(khabib.getAttackDamage());
    conor.beRepaired(5);
    conor.attack("The eagle");
    conor.highFivesGuys();
    std::cout << "------------- MAIN END --------------" << std::endl;
    return 0;
}