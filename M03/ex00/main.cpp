#include "ClapTrap.hpp"

int main()
{
    ClapTrap khabib("The eagle");
    ClapTrap conor("mcchicken");

    conor.attack("The eagle");
    khabib.takeDamage(conor.getAttackDamage());
    khabib.setAttackDamage(100);
    khabib.attack("mcchicken");
    conor.takeDamage(khabib.getAttackDamage());
    // Should not work
    conor.beRepaired(5);
    conor.attack("The eagle");
    return 0;
}