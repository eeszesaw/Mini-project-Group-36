#include <iostream>
#include "ContactManager.hpp"
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
        cout <<“     WELCOME TO CONTACT MANAGER SYSTEM  \n"；
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
            case 1: {
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
                break;
            }
            case 2: {
                string fullname;
                cout << "Enter full name of contact to edit: ";
                getline(cin, fullname);
                cout << endl;
                manager.editContact(fullname);
                cout << endl;
                break;
            }
            case 3: {
                string fullname;
                cout << "Enter full name of contact to delete: ";
                getline(cin, fullname);
                cout << endl;
                manager.deleteContact(fullname);
                cout << endl;
                break;
            }
            case 4: {
                string query;
                cout << "Enter name or phone number to search: ";
                getline(cin, query);
                cout << endl;
                manager.searchContact(query);
                cout << endl;
                break;
            }
            case 5:
                manager.viewAllContacts();
                cout << endl;
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
