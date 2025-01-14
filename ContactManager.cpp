#include "ContactManager.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Add a contact
void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
    cout << "Contact added successfully!" << endl;
}

// View all contacts
void ContactManager::viewAllContacts() {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
    } else {
        for (const auto& contact : contacts) {
            contact.display();
        }
    }
}

// Search for a contact by name or phone number
void ContactManager::searchContact(const string& query) {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getFirstName() == query || contact.getLastName() == query || contact.getPhone() == query) {
            contact.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No matching contacts found.\n";
    }
}

// Edit a contact by phone number
void ContactManager::editContact(const string& phone) {
    for (auto& contact : contacts) {
        if (contact.getPhone() == phone) {
            string firstName, lastName, email, birthday, note;
            cout << "Enter new First Name: ";
            getline(cin, firstName);
            cout << "Enter new Last Name: ";
            getline(cin, lastName);
            cout << "Enter new Email: ";
            getline(cin, email);
            cout << "Enter new Birthday (YYYY-MM-DD): ";
            getline(cin, birthday);
            cout << "Enter new Note: ";
            getline(cin, note);

            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setEmail(email);
            contact.setBirthday(birthday);
            contact.setNote(note);

            cout << "Contact updated successfully!" << endl;
            return;
        }
    }

    cout << "Contact with phone number " << phone << " not found.\n";
}

// Delete a contact by phone number
void ContactManager::deleteContact(const string& phone) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getPhone() == phone) {
            contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }

    cout << "Contact with phone number " << phone << " not found.\n";
}

// Load contacts from a file 
bool ContactManager::loadContacts() {
    
    return true;
}

// Save contacts to a file 
bool ContactManager::saveContacts() {
    
    return true;
}
