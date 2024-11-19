
class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fx);
		Fixed&	operator=(const Fixed &fx);
		int 	getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();
	private:
		int	_value;
		static const int _pointPos;
};
