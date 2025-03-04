#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <string>
// TODO: Add a brain to the animals
class Brain
{
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain& operator=(const Brain &cp);
		std::string ideas[100];
		~Brain();
	private:

};

#endif