#include <iostream>
#include <fstream>
#include <iomanip>

class Animal {
    public:
        virtual void    run( void ) const;
    private:
        int _legs;
};

class Dog: public Animal
{
    public:
        void    bark( void ) const;
        void    run( void ) const;
};

void    Animal::run() const
{
    std::cout << "Animal is running" << std::endl;
}

void    Dog::run() const
{
    std::cout << "Dog is running" << std::endl;
}

int main()
{
    std::string str;
    std::cin.unsetf(std::ios_base::skipws);
    std::cin.ignore(999999, '\n');
    std::cout << "Input : " << std::flush;
    std::cin >> str;
    std::cout << "typed " << str << "( " << str.length() << " )" << std::endl;
    return 0;
}