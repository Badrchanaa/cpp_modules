#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

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
    this->_contacts[7] = contact;
    return this->_size;
}

void    PhoneBook::_printFormatted(std::string const &str)
{
    std::cout << " | ";
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

void    PhoneBook::printContacts( void ) const
{
    std::cout << "Total contacts: " << this->_size << std::endl;
    std::cout << " | ";
    std::cout << std::setw(10) << "Index";
    std::cout << " | ";
    std::cout << std::setw(10) << "First name";
    std::cout << " | ";
    std::cout << std::setw(10) << "Last name";
    std::cout << " | ";
    std::cout << std::setw(10) << "Nickname";
    std::cout << " | " << std::endl;
    Contact const *curr;
    for (int i = 0; i < this->_size; i++)
    {
        std::cout << " | ";
        curr = this->_contacts + i;
        std::cout << std::setw(10) << i;
        PhoneBook::_printFormatted(curr->getFirstName());
        PhoneBook::_printFormatted(curr->getLastName());
        PhoneBook::_printFormatted(curr->getNickname());
        std::cout << " | " << std::endl;
    }
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