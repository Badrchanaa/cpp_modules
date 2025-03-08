#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__
#include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, int hit_points, int energy, int attack_damage);
        ClapTrap(const ClapTrap &ct);
        ClapTrap &operator=(const ClapTrap &ct);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        int     getAttackDamage();
        void    setAttackDamage(unsigned int damage);
        ~ClapTrap();
    protected:
        std::string name;
        int hit_points;
        int energy;
        int attack_damage;
};

#endif