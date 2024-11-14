#include "Contact.hpp"

Contact::Contact( void ): _firstName(""), _lastName(""), _nickname(""), _phoneNumber("00000000000"), _secret("")
{}

/* GETTERS */

Contact::getFirstName( void )
{
    return this->_firstName;
}

Contact::getLastName( void )
{
    return this->_lastName;
}

Contact::getNickname( void )
{
    return this->_nickname;
}

Contact::getPhoneNumber( void )
{
    return this->_phoneNumber;
}

Contact::getSecret( void )
{
    return this->_secret;
}

/* SETTERS */

Contact::setFirstName(std::string first_name)
{
    this->_firstName = first_name;
}

Contact::setLastName(std::string last_name)
{
    this->_lastName = last_name;
}

Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

Contact::setPhoneNumber(std::string phone_number)
{
    this->_phoneNumber = phone_number;
}

Contact::setSecret(std::string secret)
{
    this->_secret = secret;
}

Contact::~Contact() {}