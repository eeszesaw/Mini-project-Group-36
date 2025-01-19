#include <iostream>
#include "ContactManager.hpp"
#include "AddContact.hpp"  // Include the header for the addContact function

using namespace std;

int main() {
    ContactManager manager;
    const string filename = "contacts.txt";

    // Load contacts at the start
    if (!manager.loadContacts(filename)) {
        cout << "No existing contacts found. Starting fresh.\n";
    }

    int choice;

    do {
        cout << "=======================================\n";
        cout << "          CONTACT MANAGER MENU         \n";
        cout << "=======================================\n";
        cout << "1. Add Contact\n";
        cout << "2. Edit Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Search Contact\n";
        cout << "5. View All Contacts\n";
        cout << "6. Exit\n";
        cout << "---------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to clear the newline character after entering a number

        switch (choice) {
            case 1:
                addContact(manager);  // Call the addContact function
                break;
            case 2: {
                string fullname;
                cout << "Enter full name of contact to edit: ";
                getline(cin, fullname);
                cout << endl;
                manager.editContact(fullname);
                break;
            }
            case 3: {
                string fullname;
                cout << "Enter full name of contact to delete: ";
                getline(cin, fullname);
                manager.deleteContact(fullname);
                break;
            }
            case 4: {
                string query;
                cout << "Enter name or phone number to search: ";
                getline(cin, query);
                manager.searchContact(query);
                break;
            }
            case 5:
                manager.viewAllContacts();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

