#include <string>

enum Level
{
		DEBUG = 1,
		INFO,
		WARNING,
		ERROR
};

class Harl
{
	public:
		Harl(void);
		static	enum Level	strtoint(std::string level);
		void	complain(enum Level lvl) const;
		~Harl(void);
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};