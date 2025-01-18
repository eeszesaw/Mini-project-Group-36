#include "ContactManager.hpp"
#include <sstream>  
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Add a contact
void ContactManager::addContact(const Contact& newContact) {
    contacts.push_back(newContact);
    saveAllContacts(); 
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
        if (contact.getFullName() == query || contact.getPhone() == query) {
            contact.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No matching contacts found.\n";
    }
}

// Edit a contact by phone number
void ContactManager::editContact(const string& fullName) {
    for (auto& contact : contacts) {
        string contactFullName = contact.getFirstName() + " " + contact.getLastName();
        if (contactFullName == fullName) {
            string firstName, lastName, email, birthday, note;

            cout << "Enter new First Name: ";
            getline(cin, firstName);
            cout << "Enter new Last Name: ";
            getline(cin, lastName);
            cout << "Enter new Phone number: ";
            getline(cin, cPhone);
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

    cout << "Contact with phone number " << fullName << " not found.\n";
}

// Delete a contact by phone number
void ContactManager::deleteContact(const string& fullName) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        string contactFullName = it->getFirstName() + " " + it->getLastName();
        
        if (it->getPhone() == fullName) {
            contacts.erase(it);
             cout << "Contact with name '" << fullName << "' deleted successfully!" << endl;
            return;
        }
    }

    cout << "Contact with name " << fullName << " not found.\n";
}

// Load contacts from a file 
bool ContactManager::loadContacts(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open " << filename << " for reading." << endl;
        return false;
    }

    contacts.clear(); // Clear existing contacts
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName, phone, email, birthday, note;

        // Read fields separated by commas
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, birthday, ',');
        getline(ss, note);

        contacts.emplace_back(firstName, lastName, phone, email, birthday, note);
    }

    file.close();
    return true;
}

// Save contacts to a file
bool ContactManager::saveContacts(const Contact& newContact, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Could not open " << filename << " for writing." << endl;
        return false;
    }

    for (const auto& contact : contacts) {
        file << contact.getFirstName() << ","
             << contact.getLastName() << ","
             << contact.getPhone() << ","
             << contact.getEmail() << ","
             << contact.getBirthday() << ","
             << contact.getNote() << endl;
    }

    file.close();
    return true;
}

void ContactManager::saveAllContacts() {
    ofstream outFile("contacts.txt", std::ios::trunc);  // Use the member variable `filename` for the file name
    if (!outFile) {
        cerr << "Error: Could not open " << filename << " for writing.\n";
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.getFirstName() << ","
                << contact.getLastName() << ","
                << contact.getPhone() << ","
                << contact.getEmail() << ","
                << contact.getBirthday() << ","
                << contact.getNote() << endl;
    }

    outFile.close();
}