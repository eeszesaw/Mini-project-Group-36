/*Written by: HAIRUL RIDUAN HAFFIS BIN SAHALLIZAN 23303790
Function purpose: Search function for the contacts saved in contact.txt file by using name or phone number*/

#include "SearchContact.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void searchContact() {
    string query;
    cout << "Enter name or phone number to search: ";
    cin >> query;

    ifstream inFile("contacts.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string firstName, lastName, phone, email, birthday, note;
        ss >> firstName >> lastName >> phone >> email >> birthday;
        getline(ss, note);

        if (firstName == query || lastName == query || phone == query) {
            cout << "\nContact found:\n";
            cout << "Name: " << firstName << " " << lastName << endl;
            cout << "Phone: " << phone << endl;
            cout << "Email: " << email << endl;
            cout << "Birthday: " << birthday << endl;
            cout << "Note: " << note << endl;
            found = true;
            break;
        }
    }

    //if the contact entered not match to contact list contact.txt
    if (!found) {
        cout << "No contact found matching your query.\n";
    }

    inFile.close();
}

