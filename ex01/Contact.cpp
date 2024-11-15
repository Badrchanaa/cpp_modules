#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact( void ): _lastName(""), _nickname(""), _phoneNumber("00000000000"), _secret("")
{}


Contact &Contact::operator=(Contact const &ct)
{
    this->_firstName = ct._firstName;
    this->_lastName = ct._lastName;
    this->_nickname = ct._nickname;
    this->_phoneNumber = ct._phoneNumber;
    this->_secret = ct._secret;
    return *this;
}

void    Contact::print(void) const
{
    std::cout << "First name : " << this->_firstName << std::endl;
    std::cout << "Last name : " << this->_lastName << std::endl;
    std::cout << "Nickname : " << this->_nickname << std::endl;
    std::cout << "Phone : " << this->_phoneNumber << std::endl;
    std::cout << "Secret : " << this->_secret << std::endl;
}

void    Contact::_promptField(std::string prompt_msg, std::string &field)
{
    std::cout << prompt_msg << std::flush;
    std::cin >> field;
}

/* GETTERS */

std::string Contact::getFirstName( void ) const
{
    return this->_firstName;
}

std::string Contact::getLastName( void ) const
{
    return this->_lastName;
}

std::string Contact::getNickname( void ) const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber( void ) const
{
    return this->_phoneNumber;
}

std::string Contact::getSecret( void ) const
{
    return this->_secret;
}

/* SETTERS */

void Contact::setFirstName(std::string first_name)
{
    this->_firstName = first_name;
}

void Contact::setLastName(std::string last_name)
{
    this->_lastName = last_name;
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->_phoneNumber = phone_number;
}

void Contact::setSecret(std::string secret)
{
    this->_secret = secret;
}

Contact::~Contact() {}