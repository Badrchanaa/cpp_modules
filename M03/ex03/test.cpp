#include <iostream>


class A
{
    public:
        virtual void test()
        {
            std::cout << "A test" << std::endl;
        }
        int x = 10;
};

class B: public A
{
    public:
        int x = 1;
};

int main()
{
    A* pb = new B();
    B b;
    b.test();

	std::cout << b.x << std::endl;
    std::cout << pb->x << std::endl;
}