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

// Function to display the main menu
void displayMenu() {
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
    const std::string filename = "contacts.csv";

    clearScreen();
    showLoadingScreen("Loading contacts");

    if (manager.loadFromFile(filename)) {
        std::cout << "Contacts loaded successfully.\n";
    } else {
        std::cout << "No existing contacts found. Starting fresh.\n";
    }

    int choice;
    while (true) {
        clearScreen();
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
            viewContacts(manager);
            break;
        case 3:
            clearScreen();
            editContact(manager);
            break;
        case 4:
            clearScreen();
            deleteContact(manager);
            break;
        case 5:
            clearScreen();
            searchContact(manager);
            break;
        case 6:
            clearScreen();
            showLoadingScreen("Saving contacts");
            if (manager.saveToFile(filename)) {
                std::cout << "Contacts saved successfully. Goodbye!\n";
            }
            return 0;
        default:
            std::cout << "Invalid choice. Please select an option from 1 to 6.\n";
        }
    }
}
