#include <iostream>

class A {
	public:
		static void	test(){
			std::cout << "test is called" << std::endl;
		}
};
int main() {

	void (* f)(void);
	f = A::test;
   f(); 
}