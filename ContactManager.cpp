#include "ContactManager.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void ContactManager::viewAllContacts() const {
    for (const auto& contact : contacts) {
        contact.display();
        cout << "-------------------------\n";
    }
}

Contact* ContactManager::searchContact(const string& fullName) {
    for (auto& contact : contacts) {
        if (contact.getFullName() == fullName) { // Match full name
            return &contact;
        }
    }
    return nullptr;
}

bool ContactManager::editContact(const string& fullName) {
    Contact* contact = searchContact(fullName);
    if (contact) {
        string newFirstName, newLastName, newPhone, newEmail;
        cout << "Enter new first name: ";
        getline(cin, newFirstName);
        cout << "Enter new last name: ";
        getline(cin, newLastName);
        cout << "Enter new phone: ";
        getline(cin, newPhone);
        cout << "Enter new email: ";
        getline(cin, newEmail);
        contact->firstName = newFirstName;
        contact->lastName = newLastName;
        contact->phone = newPhone;
        contact->email = newEmail;
        return true;
    }
    return false;
}

bool ContactManager::deleteContact(const string& fullName) {
    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&](const Contact& c) { return c.getFullName() == fullName; }); // Match full name
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        return true;
    }
    return false;
}

void ContactManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << '\n';
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.firstName << '\n'
                << contact.lastName << '\n'
                << contact.phone << '\n'
                << contact.email << '\n';
    }
}

void ContactManager::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << '\n';
        return;
    }

    string firstName, lastName, phone, email;
    while (getline(inFile, firstName) &&
           getline(inFile, lastName) &&
           getline(inFile, phone) &&
           getline(inFile, email)) {
        contacts.emplace_back(Contact{firstName, lastName, phone, email});
    }
}
