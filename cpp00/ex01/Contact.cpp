#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}

bool Contact::setPhoneNumber(std::string phoneNumber)
{
    for (size_t i = 0; phoneNumber[i] ; i++)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
            return false;
    }
    this->phoneNumber = phoneNumber;
    return true;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}
