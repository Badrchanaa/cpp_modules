#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

int main()
{
	{
		std::cout << " -------- SCOPE START ---------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		Character other;
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(1);

		delete tmp;
		delete bob;
		delete me;
		delete src;
	}
		std::cout << " -------- SCOPE END ---------" << std::endl;
	{
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Cure());
		MateriaSource src2;
		src2 = *src;
		delete src;

		std::cout << " -------- SCOPE START ---------" << std::endl;
		Character c("cname");
		Character b("bname");
		std::cout << c.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		c = b;
		c.equip(src2.createMateria("cure"));
		AMateria *materia = src2.createMateria("unknown");
		if (materia)
			std::cout << "unknown type" << std::endl;
		c.use(0, b);
		std::cout << c.getName() << std::endl;
	}
		std::cout << " -------- SCOPE END ---------" << std::endl;
	{
		std::cout << " -------- SCOPE START ---------" << std::endl;
			IMateriaSource *src = new MateriaSource();
			MateriaSource *src2 = new MateriaSource();


			delete src;
			delete src2;
	}
		std::cout << " -------- SCOPE END ---------" << std::endl;

	return 0;
}
