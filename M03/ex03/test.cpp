#include <iostream>

class A{
    private:
    int x;
    public:
        int y;
        int getX()
        {
            return this->x;
        }
};

class B: virtual public A {
    private:
    int x;
    public:
        int y;
};

class C: virtual public A{
    private:
    int x;
    public:
        int y;
};

class D: public B, public C{
    private:
    int x;
    public:
        int y;
};

int main()
{
    D d;
    std::cout << d.getX() << std::endl;
}