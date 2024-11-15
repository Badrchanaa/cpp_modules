#include "Contact.hpp"
#include <string>
#include <iostream>

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

void    Contact::_promptField(std::string prompt_msg, std::string &field)
{
    std::cout << prompt_msg << std::flush;
    std::cin >> field;
}

void    Contact::print( void ) const
{
    std::cout << " | " << this->_firstName << " | " << this->_lastName << " | " << std::endl;
}

bool    Contact::promptFields( void )
{
    this->_promptField("First name: ", this->_firstName);
    this->_promptField("Last name: ", this->_lastName);
    this->_promptField("Nickname: ", this->_nickname);
    this->_promptField("Phone: ", this->_phoneNumber);
    this->_promptField("Secret: ", this->_secret);
    return true;
}

/* GETTERS */

std::string Contact::getFirstName( void )
{
    return this->_firstName;
}

std::string Contact::getLastName( void )
{
    return this->_lastName;
}

std::string Contact::getNickname( void )
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber( void )
{
    return this->_phoneNumber;
}

std::string Contact::getSecret( void )
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