/*Written by: SAW EE-SZE 23301850
Function purpose: Implements the methods for adding, viewing, searching, editing, deleting, saving to a file, and loading from a file*/

#include "ContactManager.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

// Add a contact
void ContactManager::addContact(const Contact& newContact) {
    contacts.push_back(newContact);
    saveAllContacts();
    cout << "Contact added successfully!" << endl;
}

// View all contacts with pagination
void ContactManager::viewAllContacts() {
    const int pageSize = 5; // Number of contacts per page
    int totalContacts = contacts.size();
    if (totalContacts == 0) {
        cout << "No contacts to display." << endl;
        return;
    }

    int currentPage = 0;
    bool running = true;

    while (running) {
        int startIdx = currentPage * pageSize;
        int endIdx = min(startIdx + pageSize, totalContacts);

        cout << "=======================================" << endl;
        cout << "              CONTACT LIST             " << endl;
        cout << "=======================================" << endl;
        cout << left << setw(5) << "No."
             << setw(20) << "Name"
             << setw(15) << "Phone"
             << setw(25) << "Email" << endl;
        cout << "---------------------------------------" << endl;

        for (int i = startIdx; i < endIdx; ++i) {
            const auto& contact = contacts[i];
            cout << left << setw(5) << (i + 1)
                 << setw(20) << (contact.getFirstName() + " " + contact.getLastName())
                 << setw(15) << contact.getPhone()
                 << setw(25) << contact.getEmail() << endl;
        }

        cout << "---------------------------------------" << endl;
        cout << "Page " << (currentPage + 1) << " of "
             << ((totalContacts + pageSize - 1) / pageSize) << endl;

        cout << "[N] Next Page  [P] Previous Page  [E] Exit" << endl;
        cout << "Enter choice: ";
        string choice;
        cin >> choice;

        if (choice == "N" || choice == "n") {
            if (endIdx < totalContacts) {
                ++currentPage;
            } else {
                cout << "You are on the last page." << endl;
            }
        } else if (choice == "P" || choice == "p") {
            if (currentPage > 0) {
                --currentPage;
            } else {
                cout << "You are on the first page." << endl;
            }
        } else if (choice == "E" || choice == "e") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
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
        cout << "No matching contacts found." << endl;
    }
}

// Edit a contact by name
void ContactManager::editContact(const string& fullName) {
    for (auto& contact : contacts) {
        if (contact.getFullName() == fullName) {
            string firstName, lastName, phone, email, birthday, note;

            cout << "Enter new First Name: ";
            getline(cin, firstName);
            cout << "Enter new Last Name: ";
            getline(cin, lastName);
            cout << "Enter new Phone number: ";
            getline(cin, phone);
            cout << "Enter new Email: ";
            getline(cin, email);
            cout << "Enter new Birthday (YYYY-MM-DD): ";
            getline(cin, birthday);
            cout << "Enter new Note: ";
            getline(cin, note);

            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setPhone(phone);
            contact.setEmail(email);
            contact.setBirthday(birthday);
            contact.setNote(note);

            cout << "Contact updated successfully!" << endl;
            saveAllContacts();
            return;
        }
    }

    cout << "Contact with name " << fullName << " not found." << endl;
}

// Delete a contact by full name
void ContactManager::deleteContact(const string& fullName) {
    auto it = remove_if(contacts.begin(), contacts.end(), [&fullName](const Contact& contact) {
        return contact.getFullName() == fullName;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully!" << endl;
        saveAllContacts();
    } else {
        cout << "Contact with name " << fullName << " not found." << endl;
    }
}

// Load contacts from a file
bool ContactManager::loadContacts(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open " << filename << " for reading." << endl;
        return false;
    }

    contacts.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string firstName, lastName, phone, email, birthday, note;

        if (!getline(ss, firstName, ',') || !getline(ss, lastName, ',') ||
            !getline(ss, phone, ',') || !getline(ss, email, ',') ||
            !getline(ss, birthday, ',') || !getline(ss, note)) {
            cerr << "Skipping invalid line: " << line << endl;
            continue;
        }

        contacts.emplace_back(firstName, lastName, phone, email, birthday, note);
    }

    file.close();
    return true;
}

// Save all contacts to a file
void ContactManager::saveAllContacts() {
    ofstream outFile("contacts.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open contacts.txt for writing." << endl;
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
