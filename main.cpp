#include <iostream>
#include <vector>
#include "AddContact.hpp"
#include "Contact.hpp"
#include "ContactManager.hpp"
#include "deleteContact.hpp"
#include "EditContact.hpp"
#include "ViewContact.hpp"
#include <string>

// Updated main.cpp with all functionalities handled through ContactManager
void displayMenu() {
    std::cout << "\n================= Contact Manager =================\n";
    std::cout << "1. Add Contact\n";
    std::cout << "2. View Contacts\n";
    std::cout << "3. Edit Contact\n";
    std::cout << "4. Delete Contact\n";
    std::cout << "5. Exit\n";
    std::cout << "=================================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ContactManager manager;
    std::string firstName, lastName, fullName;
    int choice;
    bool isRunning = true;

    while (isRunning) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from the input buffer

        switch (choice) {
            case 1: {
               std::string phone, email;
                Contact newContact;
                std::cout << "Enter first name: ";
                std::getline(std::cin, firstName);
                newContact.setFirstName(firstName);

                std::cout << "Enter last name: ";
                std::getline(std::cin, lastName);
                newContact.setLastName(lastName);

                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                newContact.setPhone(phone);

                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                newContact.setEmail(email);

                manager.addContact(newContact);
                break;
            }
            case 2:
                manager.viewAllContacts();
                break;
            case 3:
                std::cout << "Enter the name of the contact to edit: ";
                std::getline(std::cin, name);
                if (!manager.editContact(name)) {
                    std::cout << "Contact not found.\n";
                }
                break;
            case 4:
                std::cout << "Enter the name of the contact to delete: ";
                std::getline(std::cin, name);
                if (!manager.deleteContact(name)) {
                    std::cout << "Contact not found.\n";
                }
                break;
            case 5:
                std::cout << "Exiting Contact Manager. Goodbye!\n";
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
