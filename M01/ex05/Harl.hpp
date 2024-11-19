#include <string>

class Harl
{
	public:
		Harl(void);
		static	int	strtoint(std::string level);
		void	complain(std::string level) const;
		~Harl(void);
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};