#include "EditContact.hpp"
#include <iostream>
#include <string>

void editContact(ContactManager& manager) {
    std::string name;

    std::cout << "Enter the name of the contact to edit: ";
    std::getline(std::cin, name);

    if (!manager.editContact(name)) {
        std::cout << "Error: Contact not found.\n";
    }

    // Pause before returning to the main menu
    std::cout << "\nPress Enter to return to the main menu...";
    std::cin.get(); // Wait for Enter key
}
