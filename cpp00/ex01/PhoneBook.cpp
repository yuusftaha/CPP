#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    PhoneBook::currentIndex = 0;
}

int PhoneBook::getCurrentIndex()
{
    return this->currentIndex;
}

void PhoneBook::setCurrentIndex(int count)
{
    this->currentIndex += count;
}

bool PhoneBook::addContact()
{
    PhoneBook phonebook;
    std::string value;
    int i = 0;

    while (i < 8)
    {
        /* code */
    }
    
    std::cout << "First Name = ";
    std::getline(std::cin, value);
    if (!value.empty())
        phonebook.contact[i].setFirstName(value);

    std::cout << "Last Name = ";
    std::getline(std::cin, value);
    if (!value.empty())
        phonebook.contact[i].setLastName(value);

    std::cout << "Nick Name = ";
    std::getline(std::cin, value);
    if (!value.empty())
        phonebook.contact[i].setNickName(value);
    
    std::cout << "Phone Number = ";
    std::getline(std::cin, value);
    if (value.empty() || !phonebook.contact[i].setPhoneNumber(value))
        return false;
    
    std::cout << "Darkest Secret = ";
    std::getline(std::cin, value);
    if (!value.empty())
        phonebook.contact[i].setDarkestSecret(value);

    
    setCurrentIndex(1);
    return true;
}

void PhoneBook::searchContact()
{
    std::cout << "------------------PHONEBOOK------------------" << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

    int i = 0;
    while (i < 8)
    {
        std::cout << "|";
        std::cout << std::setw(10) << (i + 1) << "|"; 
        std::cout << std::setw(10) << contact[i].getFirstName() << "|";
        std::cout << std::setw(10) << contact[i].getLastName() << "|";
        std::cout << std::setw(10) << contact[i].getNickName() << "|" << std::endl;
        i++;
    }
}
