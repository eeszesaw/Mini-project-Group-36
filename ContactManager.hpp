#ifndef CONTACTMANAGER_HPP
#define CONTACTMANAGER_HPP

#include <vector>
#include "Contact.hpp"

class ContactManager {
public:
    void addContact(const Contact& newContact);
    void viewAllContacts();
    void searchContact(const std::string& query);
    void editContact(const std::string& fullName);
    void deleteContact(const std::string& fullName);
    bool loadContacts(const std::string& filename);
    bool saveContacts(const Contact& newContact, const std::string& filename);
    void saveAllContacts();  // Save all contacts to file

private:
    std::vector<Contact> contacts;  // Stores all contacts in memory
    const std::string filename = "contacts.txt";
    
};

#endif 
