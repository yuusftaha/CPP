#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
    private:
    Contact contact[8];
    int currentIndex;

    public:
    PhoneBook();
    void addContact();
    void searchContact();
    int getCurrentIndex();
    void setCurrentIndex(int count);
};

void checkIsEmpty(std::string &value, std::string msg, std::string valuetype);
void checkPhoneNum(std::string &num);

#endif