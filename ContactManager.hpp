#ifndef CONTACTMANAGER_HPP
#define CONTACTMANAGER_HPP

#include <vector>
#include "Contact.hpp"

class ContactManager {
public:
    void addContact(const Contact& contact);
    void viewAllContacts();
    void searchContact(const std::string& query);
    void editContact(const std::string& phone);
    void deleteContact(const std::string& phone);
    bool loadContacts(const std::string& filename);
    bool saveContacts(const std::string& filename);

private:
    std::vector<Contact> contacts;
};

#endif 
