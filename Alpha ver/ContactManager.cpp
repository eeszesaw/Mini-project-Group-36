#include "ContactManager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype> // For std::tolower

// Utility function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// Add a new contact
void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
    std::cout << "Contact added successfully!\n";
}

// View all contacts
void ContactManager::viewAllContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts available.\n";
        return;
    }

    std::cout << "\n=== Contact List ===\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        const auto& contact = contacts[i];
        std::cout << "Contact " << (i + 1) << ":\n";
        std::cout << "  Name: " << contact.getName() << "\n";
        std::cout << "  Phone: " << contact.getPhoneNumber() << "\n";
        std::cout << "  Email: " << contact.getEmail() << "\n";
        std::cout << "-----------------------------\n";
    }
}

// Non-const version of searchContact (allows modification)
Contact* ContactManager::searchContact(const std::string& name) {
    std::string lowerName = toLower(name); // Normalize input name
    for (auto& contact : contacts) {
        if (toLower(contact.getName()) == lowerName) { // Case-insensitive comparison
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no match is found
}

// Const version of searchContact (does not allow modification)
const Contact* ContactManager::searchContact(const std::string& name) const {
    std::string lowerName = toLower(name); // Normalize input name
    for (const auto& contact : contacts) {
        if (toLower(contact.getName()) == lowerName) { // Case-insensitive comparison
            return &contact;
        }
    }
    return nullptr; // Return nullptr if no match is found
}

// Edit an existing contact
bool ContactManager::editContact(const std::string& name) {
    Contact* contact = searchContact(name); // Use non-const searchContact
    if (!contact) {
        std::cout << "Contact not found.\n";
        return false;
    }

    std::string newName, newPhone, newEmail;
    std::cout << "Editing contact: " << name << "\n";

    std::cout << "Enter new name (leave empty to keep current): ";
    std::getline(std::cin, newName);
    if (!newName.empty()) contact->setName(newName);

    std::cout << "Enter new phone (leave empty to keep current): ";
    std::getline(std::cin, newPhone);
    if (!newPhone.empty()) contact->setPhoneNumber(newPhone);

    std::cout << "Enter new email (leave empty to keep current): ";
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) contact->setEmail(newEmail);

    std::cout << "Contact updated successfully!\n";
    return true;
}

// Delete a contact by name
bool ContactManager::deleteContact(const std::string& name) {
    auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
        return toLower(c.getName()) == toLower(name); // Case-insensitive comparison
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted successfully!\n";
        return true;
    }

    std::cout << "Contact not found.\n";
    return false;
}

// Save contacts to a file
bool ContactManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for saving.\n";
        return false;
    }

    for (const auto& contact : contacts) {
        file << contact.getName() << ","
             << contact.getPhoneNumber() << ","
             << contact.getEmail() << "\n";
    }

    file.close();
    return true;
}

// Load contacts from a file
bool ContactManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for loading.\n";
        return false;
    }

    contacts.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, phone, email;

        std::getline(ss, name, ',');
        std::getline(ss, phone, ',');
        std::getline(ss, email, ',');

        if (!name.empty() && !phone.empty() && !email.empty()) {
            contacts.emplace_back(name, phone, email);
        }
    }

    file.close();
    return true;
}
