#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &fx);
		Fixed&	operator=(const Fixed &fx);
		
		float	operator++(int);
		float	operator++();
		float	operator--(int);
		float	operator--();

		static Fixed	const &min(Fixed const &fx1, Fixed const &fx2);
		static Fixed	&min(Fixed &fx1, Fixed &fx2);
		static Fixed	const &max(Fixed const &fx1, Fixed const &fx2);
		static Fixed	&max(Fixed &fx1, Fixed &fx2);

		bool	operator>(const Fixed &fx);
		bool	operator<(const Fixed &fx);
		bool	operator<=(const Fixed &fx);
		bool	operator>=(const Fixed &fx);
		bool	operator!=(const Fixed &fx);
		bool	operator==(const Fixed &fx);

		Fixed	operator+(const Fixed &fx);
		Fixed	operator-(const Fixed &fx);
		Fixed	operator*(const Fixed &fx);
		Fixed	operator/(const Fixed &fx);


		std::string	toString(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();
	private:
		int	_value;
		static const int _pointPos;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fx);

#endif