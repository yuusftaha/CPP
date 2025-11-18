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
    bool addContact();
    void searchContact();
    int getCurrentIndex();
    void setCurrentIndex(int count);
};

#endif