#ifndef CONTACT_MANAGER_HPP
#define CONTACT_MANAGER_HPP

#include "Contact.hpp"
#include <vector>
#include <string>

class ContactManager {
public:
    void addContact(const Contact& contact);
    void viewAllContacts() const;

    // Overloaded searchContact: const and non-const versions
    Contact* searchContact(const std::string& name);
    const Contact* searchContact(const std::string& name) const;

    bool editContact(const std::string& name);
    bool deleteContact(const std::string& name);

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

private:
    std::vector<Contact> contacts;
};

#endif // CONTACT_MANAGER_HPP
