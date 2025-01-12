#include "SearchContact.hpp"
#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

void searchContact(const ContactManager& manager) {
    std::string name;

    while (true) {
        std::cout << "Enter the name of the contact to search (or type 'exit' to cancel): ";
        std::getline(std::cin, name);

        // Check if the user entered "exit"
        if (name == "exit") {
            std::cout << "You entered 'exit'. Do you want to cancel the search? (yes/no): ";
            std::string confirmation;
            std::getline(std::cin, confirmation);

            // Confirm if the user wants to exit
            if (confirmation == "yes" || confirmation == "y") {
                std::cout << "Search canceled. Returning to the main menu.\n";
                break;
            }
            // Otherwise, continue searching for "exit" as a name
        }

        // Ensure name is not empty
        if (name.empty()) {
            std::cout << "Error: Name cannot be empty. Please try again.\n";
            continue;
        }

        // Search for the contact
        const Contact* contact = manager.searchContact(name); // Perform case-insensitive search
        if (contact) {
            std::cout << "\nContact Found:\n";
            std::cout << "  Name: " << contact->getName() << "\n";
            std::cout << "  Phone: " << contact->getPhoneNumber() << "\n";
            std::cout << "  Email: " << contact->getEmail() << "\n";
        } else {
            std::cout << "No contact found with the name \"" << name << "\".\n";
        }

        // Prompt to continue or return
        std::cout << "\nPress Enter to search again or type 'exit' to cancel: ";
        std::getline(std::cin, name);
        if (name == "exit") {
            std::cout << "Search canceled. Returning to the main menu.\n";
            break;
        }
    }
}
