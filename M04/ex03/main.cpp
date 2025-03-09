#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <typeinfo>
#include <iostream>

int main()
{
	{
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
	{
			IMateriaSource *src = new MateriaSource();
			MateriaSource *src2 = new MateriaSource();

			std::cout << "type: " << typeid(Cure).name() << std::endl;
			std::cout << "type: " << typeid(Ice).name() << std::endl;
			std::cout << "type: " << typeid(Character).name() << std::endl;
			std::cout << "type: " << typeid(ICharacter).name() << std::endl;
			std::cout << "type: " << typeid(AMateria).name() << std::endl;
			std::cout << "type: " << typeid(IMateriaSource).name() << std::endl;
			std::cout << "type: " << typeid(MateriaSource).name() << std::endl;

			delete src;
			delete src2;
	}

	return 0;
}
