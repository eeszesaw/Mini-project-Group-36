#include "EditContact.hpp"

Contact::Contact(std::string n, std::string p, std::string e) : name(n), phoneNumber(p), email(e) {}

void ContactDirectory::editContact(const std::string& name) {
    auto it = contacts.find(name);
    if (it != contacts.end()) {
        int choice;
        std::cout << "Editing contact: " << it->second.name << "\n";
        std::cout << "1. Edit Name\n";
        std::cout << "2. Edit Phone Number\n";
        std::cout << "3. Edit Email\n";
        std::cout << "Choose an option (1-3): ";
        std::cin >> choice;

        std::cin.ignore(); 

        switch (choice) {
            case 1: {
                std::string newName;
                std::cout << "Enter new name: ";
                std::getline(std::cin, newName);
                it->second.name = newName;
                contacts[newName] = it->second; 
                contacts.erase(it); 
                std::cout << "Name updated successfully.\n";
                break;
            }
            case 2: {
                std::string newPhoneNumber;
                std::cout << "Enter new phone number: ";
                std::getline(std::cin, newPhoneNumber);
                it->second.phoneNumber = newPhoneNumber;
                std::cout << "Phone number updated successfully.\n";
                break;
            }
            case 3: {
                std::string newEmail;
                std::cout << "Enter new email: ";
                std::getline(std::cin, newEmail);
                it->second.email = newEmail;
                std::cout << "Email updated successfully.\n";
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    } else {
        std::cout << "Contact not found.\n";
    }
}