#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string literal);
	private:
		ScalarConverter(void);
		static	bool	_isalpha(char c);
		static	bool	_validate(std::string literal);
		static	bool	_isdigit(char c);
		static	void		_printInt(double num);
		static	void		_printChar(double num);
		static	void		_printFloat(double num);
};

#endif