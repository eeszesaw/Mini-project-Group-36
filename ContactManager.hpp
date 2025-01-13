#ifndef CONTACTMANAGER_HPP
#define CONTACTMANAGER_HPP

#include "Contact.hpp"
#include <vector>
#include <string>

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void viewAllContacts() const;
    Contact* searchContact(const std::string& fullName);
    bool editContact(const std::string& fullName);
    bool deleteContact(const std::string& fullName);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // CONTACTMANAGER_HPP

