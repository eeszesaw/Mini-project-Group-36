#include "AddContact.hpp"
#include <iostream>
#include <string>
#include <regex> // For email validation

void addContact(ContactManager& manager) {
    std::string name, phone, email;

    do {
        std::cout << "Enter name (cannot be blank): ";
        std::getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Error: Name cannot be blank. Please try again.\n";
        }
    } while (name.empty());

    do {
        std::cout << "Enter phone (cannot be blank): ";
        std::getline(std::cin, phone);
        if (phone.empty()) {
            std::cout << "Error: Phone number cannot be blank. Please try again.\n";
        }
    } while (phone.empty());

    std::regex emailPattern(R"((\w+)(\.?)(\w*)@(\w+)\.(\w+))");
    do {
        std::cout << "Enter email (must be valid): ";
        std::getline(std::cin, email);
        if (email.empty() || !std::regex_match(email, emailPattern)) {
            std::cout << "Error: Invalid email format. Please try again.\n";
        }
    } while (email.empty() || !std::regex_match(email, emailPattern));

    manager.addContact(Contact(name, phone, email));
    std::cout << "Contact added successfully!\n";
}
