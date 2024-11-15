#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        int   	 addContact(Contact contact);
        Contact *searchContact(unsigned int id);
		int		getSize(void) const;
        ~PhoneBook();
    private:
        Contact _contacts[8];
        int     _size;
};


#endif