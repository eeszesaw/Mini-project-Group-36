#include "ViewContact.hpp"
#include <iostream>

void viewContacts(const ContactManager& manager) {
    std::cout << "===== VIEW ALL CONTACTS =====\n";
    manager.viewAllContacts(); // Display all contacts

    // Pause before returning to the main menu
    std::cout << "\nPress Enter to return to the main menu...";
    std::cin.get(); // Wait for Enter key
}
