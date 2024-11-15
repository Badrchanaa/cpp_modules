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
    Animal a;
    Animal *a2 = new Dog();
    a2->run();
    return 0;
}