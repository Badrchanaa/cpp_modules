#include <iostream>
#include <string>

class A{
	public:
	A(){};
	virtual void purefunction(){
		std::cout << "A::purefunction called" << std::endl;
	};
};
class B: public A{
	public:
	B(std::string s=""): A(){};
	A operator=(const B &cp)
	{
		return *this;
	}
};

void	test(A &a)
{
	std::cout << "test is called" << std::endl;
}

int main()
{
	B b;
	b.purefunction();
	test(b);
	return 0;
}
