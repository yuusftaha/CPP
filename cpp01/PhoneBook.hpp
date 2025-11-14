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
};

#endif