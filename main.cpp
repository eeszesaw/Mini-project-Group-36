#include <iostream>
#include <thread>
#include <chrono>
#include "ContactManager.hpp"

using namespace std;

// Function to clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear");  // For Linux/macOS
#endif
}

// Function to display a loading screen
void showLoadingScreen(const string& message) {
    clearScreen();
    cout << message << endl;
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));  // Delay for effect
    }
    cout << endl;
}

int main() {
    ContactManager manager;
    const string filename = "contacts.txt";

    // Load contacts at the start
    showLoadingScreen("Loading contacts");
    if (!manager.loadContacts(filename)) {
        cout << "No existing contacts found. Starting fresh.\n";
    }

    int choice;

    do {
        clearScreen();  // Refresh screen
        cout << "\n=== Contact Manager ===\n";
        cout << "1. Add Contact\n";
        cout << "2. Edit Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Search Contact\n";
        cout << "5. View Contacts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character after entering a number

        switch (choice) {
            case 1: {
                clearScreen();
                string firstName, lastName, phone, email, birthday, note;
                cout << "Enter First Name: ";
                getline(cin, firstName);
                cout << "Enter Last Name: ";
                getline(cin, lastName);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Email: ";
                getline(cin, email);
                cout << "Enter Birthday (YYYY-MM-DD): ";
                getline(cin, birthday);
                cout << "Enter Note: ";
                getline(cin, note);

                Contact newContact(firstName, lastName, phone, email, birthday, note);
                manager.addContact(newContact);

                showLoadingScreen("Saving contact");
                cout << "Contact added successfully!\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            case 2: {
                clearScreen();
                string fullname;
                cout << "Enter full name of contact to edit: ";
                getline(cin, fullname);

                showLoadingScreen("Loading contact details");
                manager.editContact(fullname);

                cout << "Contact updated successfully!\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            case 3: {
                clearScreen();
                string fullname;
                cout << "Enter full name of contact to delete: ";
                getline(cin, fullname);

                showLoadingScreen("Deleting contact");
                manager.deleteContact(fullname);

                cout << "Contact deleted successfully!\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            case 4: {
                clearScreen();
                string query;
                cout << "Enter name or phone number to search: ";
                getline(cin, query);

                showLoadingScreen("Searching contacts");
                manager.searchContact(query);

                cout << "Search complete!\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            case 5:
                clearScreen();
                manager.viewAllContacts();
                cout << "\nPress Enter to continue...";
                cin.get();  // Wait for the user to press Enter
                break;
            case 6:
                showLoadingScreen("Exiting program");
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }
    } while (choice != 6);

    return 0;
}
