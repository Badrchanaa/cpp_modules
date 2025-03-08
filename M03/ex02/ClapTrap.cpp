#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy(10), attack_damage(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) 
{
    *this = ct;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy, int attack_damage):
    name(name), hit_points(hit_points), energy(energy), attack_damage(attack_damage)
{

    std::cout << "ClapTrap all constructor called" << std::endl;

}

ClapTrap &ClapTrap::operator=(ClapTrap const &ct)
{
    if (this == &ct)
        return *this;
    this->name = ct.name;
    this->energy = ct.energy;
    this->hit_points = ct.hit_points;
    this->attack_damage = ct.attack_damage;
    return *this;
}

void    ClapTrap::attack(const std::string &target)
{
    if (energy <= 0 || hit_points <= 0)
        return ;
    this->energy--;
    std::cout << "ClapTrap " << this->name << " attacks " << target \
        << ", causing " << this->attack_damage << " points of damage!";
    std::cout << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (energy <= 0 || hit_points <= 0)
        return ;
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount \
        << " damage";
    if (this->hit_points <= 0)
        std::cout << " (died).";
    std::cout << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energy <= 0 || hit_points <= 0)
        return ;
    this->energy--;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " gains " << amount \
        << " point(s) of energy." << std::endl;
}

int ClapTrap::getAttackDamage()
{
    return this->attack_damage;
}

void ClapTrap::setAttackDamage(unsigned int attack_damage)
{
    this->attack_damage = attack_damage;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}