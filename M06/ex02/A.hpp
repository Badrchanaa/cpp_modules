#ifndef __A_HPP__
# define __A_HPP__

#include <string>
#include "Base.hpp"
#include <iostream>

class A: public Base
{
	public:
		void	iam(void)
		{
			std::cout << "iam A" << std::endl;
		}
};

#endif