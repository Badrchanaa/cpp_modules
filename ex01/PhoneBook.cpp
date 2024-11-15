#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ): _size(0) {

}

int    PhoneBook::addContact(Contact contact) {
    int i;
    if (this->_size < 8)
    {
        this->_contacts[this->_size] = contact;
        return  ++this->_size;
    }
    for (i = 1; i < 8; i++)
    {
        this->_contacts[i - 1] = this->_contacts[i];
    }
    this->_contacts[i] = contact;
    return  ++this->_size;
}

Contact *PhoneBook::searchContact(unsigned int id) {
    if (id  >= (unsigned int) this->_size)
        return NULL;
    return this->_contacts + id;
}

int PhoneBook::getSize( void ) const
{
    return this->_size;
}

PhoneBook::~PhoneBook()
{}