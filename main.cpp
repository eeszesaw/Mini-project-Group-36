#include "ContactManager.hpp"
#include "AddContact.hpp"
#include "ViewContact.hpp"
#include "EditContact.hpp"
#include "deleteContact.hpp"
#include "SearchContact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <thread>
#include <chrono>

// Function to clear the screen
void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// Function to show a welcome message
void showWelcomeMessage() {
    clearScreen();
    std::cout << "=======================================\n";
    std::cout << "       WELCOME TO CONTACT MANAGER       \n";
    std::cout << "=======================================\n";
    std::cout << "   Manage your contacts efficiently!    \n";
    std::cout << "---------------------------------------\n";
    std::cout << "      Loading the system, please wait...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}

// Function to display the main menu
void displayMenu() {
    clearScreen();
    std::cout << "=======================================\n";
    std::cout << "        CONTACT MANAGEMENT SYSTEM      \n";
    std::cout << "=======================================\n";
    std::cout << "  1. Add Contact                       \n";
    std::cout << "  2. View All Contacts                 \n";
    std::cout << "  3. Edit Contact                      \n";
    std::cout << "  4. Delete Contact                    \n";
    std::cout << "  5. Search Contact                    \n";
    std::cout << "  6. Exit                              \n";
    std::cout << "=======================================\n";
    std::cout << "Enter your choice: ";
}

// Function to show a loading animation
void showLoadingScreen(const std::string& message, int durationMs = 1500) {
    std::cout << message;
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(durationMs / 3));
        std::cout << ".";
        std::cout.flush();
    }
    std::cout << "\n";
}

int main() {
    ContactManager manager;

    // Show the welcome message
    showWelcomeMessage();

    // Load contacts
    showLoadingScreen("Loading contacts");
    if (manager.loadContacts("contacts.txt")) {
        std::cout << "Contacts loaded successfully.\n\n";
    } else {
        std::cout << "No existing contacts found. Starting fresh.\n\n";
    }

    int choice;
    while (true) {
        displayMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            clearScreen();
            addContact(manager);
            break;
        case 2:
            clearScreen();
            manager.viewAllContacts();
            break;
        case 3:
            clearScreen();
            {
                std::string fullName;
                std::cout << "Enter the full name of the contact to edit: ";
                std::getline(std::cin, fullName);
                manager.editContact(fullName);
            }
            break;
        case 4:
            clearScreen();
            {
                std::string fullName;
                std::cout << "Enter the full name of the contact to delete: ";
                std::getline(std::cin, fullName);
                manager.deleteContact(fullName);
            }
            break;
        case 5:
            clearScreen();
            {
                std::string query;
                std::cout << "Enter search query: ";
                std::getline(std::cin, query);
                manager.searchContact(query);
            }
            break;
        case 6:
            clearScreen();
            showLoadingScreen("Saving contacts");
            manager.saveAllContacts();
            std::cout << "Contacts saved successfully. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please select an option from 1 to 6.\n";
        }

        std::cout << "\nPress Enter to return to the main menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
