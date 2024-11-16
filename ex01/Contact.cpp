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

bool    Contact::validPhoneNumber(std::string const &phoneNumber)
{
    return phoneNumber.find_first_not_of("0123456789") == std::string::npos;
}

void    Contact::_promptField(std::string prompt_msg, std::string &field)
{
    if (std::cin.fail())
        return ;
    std::cout << prompt_msg << std::flush;
    std::getline(std::cin, field);
    while (field.empty())
    {
        std::cout << "Contact fields can't be empty." << std::endl;
        std::cout << prompt_msg << std::flush;
        std::getline(std::cin, field);
    }
}

bool    Contact::promptFields( void )
{
    std::cout << "\033c" << std::flush;
    this->_promptField("\tFirst name: ", this->_firstName);
    this->_promptField("\tLast name: ", this->_lastName);
    this->_promptField("\tNickname: ", this->_nickname);
    this->_promptField("\tPhone: ", this->_phoneNumber);
    while (!Contact::validPhoneNumber(this->_phoneNumber))
    {
        std::cout << "Phone number must contain only numbers." << std::endl;
        this->_promptField("\tPhone: ", this->_phoneNumber);
    }
    this->_promptField("\tSecret: ", this->_secret);
    std::cout << "\033c" << std::flush;
    return std::cin.good();
}

void    Contact::print(void) const
{
    std::cout << "\tFirst name : " << this->_firstName << std::endl;
    std::cout << "\tLast name : " << this->_lastName << std::endl;
    std::cout << "\tNickname : " << this->_nickname << std::endl;
    std::cout << "\tPhone : " << this->_phoneNumber << std::endl;
    std::cout << "\tSecret : " << this->_secret << std::endl;
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