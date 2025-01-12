#include "deleteContact.hpp"
#include <iostream>
#include <string>

void deleteContact(ContactManager& manager) {
    std::string name;

    std::cout << "Enter the name of the contact to delete: ";
    std::getline(std::cin, name);

    if (manager.deleteContact(name)) {
        std::cout << "Contact deleted successfully!\n";
    } else {
        std::cout << "Error: Contact not found.\n";
    }

    // Pause before returning to the main menu
    std::cout << "\nPress Enter to return to the main menu...";
    std::cin.get(); // Wait for Enter key
}
