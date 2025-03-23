#ifndef __DATA_HPP__
# define __DATA_HPP__

#include <string>

class Data
{
	public:
		Data(void);
		Data(std::string str, unsigned int num);
		Data(const Data &other);
		Data& operator=(const Data &other);
		~Data();
	// private:
		unsigned int	num;
		std::string		str;
};

#endif