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

std::string fixLength(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void checkIsEmpty(std::string &value, std::string msg, std::string valuetype)
{
    while (value.empty())
    {
        std::cout << msg << std::endl;
        std::cout << valuetype;
        if (!std::getline(std::cin, value)) 
            std::exit(0);
    }
}

void checkPhoneNum(std::string &num)
{
    for (size_t i = 0; i < num.length(); i++)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            std::cout << "Phone Number must be digit." << std::endl;
            std::cout << "Phone Number = ";
            if (!std::getline(std::cin, num)) 
                std::exit(0);
            checkIsEmpty(num, "Phone Number cannot be left blank", "Phone Number = ");
            i = -1; 
        } 
    }
}

void PhoneBook::addContact()
{

    std::string value;

    if (getCurrentIndex() == 8)
        setCurrentIndex(-8);
        
    std::cout << "First Name = ";
    if (!std::getline(std::cin, value))
        exit(0);
    checkIsEmpty(value, "First Name cannot be left blank", "First Name = ");
    this->contact[getCurrentIndex()].setFirstName(value);

    std::cout << "Last Name = ";
    if (!std::getline(std::cin, value))
        exit(0);
    checkIsEmpty(value, "Last Name cannot be left blank", "Last Name = ");
    this->contact[getCurrentIndex()].setLastName(value);

    std::cout << "Nick Name = ";
    if (!std::getline(std::cin, value))
        exit(0);
    checkIsEmpty(value, "Nick Name cannot be left blank", "Nick Name = ");
    this->contact[getCurrentIndex()].setNickName(value);
    
    std::cout << "Phone Number = ";
    if (!std::getline(std::cin, value))
        exit(0);
    checkIsEmpty(value, "Phone Number cannot be left blank", "Phone Number = ");
    checkPhoneNum(value);
    this->contact[getCurrentIndex()].setPhoneNumber(value);
    
    std::cout << "Darkest Secret = ";
    if (!std::getline(std::cin, value))
        exit(0);
    checkIsEmpty(value, "Darkest Secret cannot be left blank", "Darkest Secret = ");
    this->contact[getCurrentIndex()].setDarkestSecret(value);

    setCurrentIndex(1);
}

void PhoneBook::searchContact()
{
    std::string input;    
    int index;

    std::cout << "------------------PHONEBOOK------------------" << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    int i = 0;
    while (i < 8)
    {
        std::cout << "|";
        std::cout << std::setw(10) << (i + 1) << "|"; 
        std::cout << std::setw(10) << fixLength(this->contact[i].getFirstName()) << "|";
        std::cout << std::setw(10) << fixLength(this->contact[i].getLastName()) << "|";
        std::cout << std::setw(10) << fixLength(this->contact[i].getNickName()) << "|" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        i++;
    }
    while (true)
    {
        std::cout << "Search index: ";
        if (!std::getline(std::cin, input))
            exit(0);
        index = std::atoi(input.c_str());
        if (index < 1 || index > 8)
        {
            std::cout << "Invalid index!" << std::endl;
            continue;
        }
        if (this->contact[index - 1].getFirstName().empty())
        {
            std::cout << "There is no contact at index " << index << "!" << std::endl;
            continue; 
        }
        break; 
    }
    std::cout << std::endl;
    std::cout << "First Name    : " << this->contact[index - 1].getFirstName() << std::endl;
    std::cout << "Last Name     : " << this->contact[index - 1].getLastName() << std::endl;
    std::cout << "Nickname      : " << this->contact[index - 1].getNickName() << std::endl;
    std::cout << "Phone Number  : " << this->contact[index - 1].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contact[index - 1].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}
