#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		Zombie();
		void	announce(void);
		void	setName(std::string name);
		~Zombie();

	private:
		std::string _name;
};

#endif