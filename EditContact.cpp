#include "EditContact.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void editContact() {
    string fullName;
    cout << "Enter full name of the contact you want to edit: ";
    cin.ignore();  // to clear the input buffer before reading the full name
    getline(cin, fullName);  // Use getline to capture full names with spaces
    
    ifstream inFile("contacts.txt");
    if (!inFile) {
        cout << "Error opening file.\n";
        return;
    }

    vector<string> contacts;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        contacts.push_back(line);
    }
    inFile.close();

    ofstream outFile("contacts.txt", ios::trunc);
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }
    
    for (auto& contact : contacts) {
        stringstream ss(contact);
        string firstName, lastName, cPhone, email, birthday, note;
        ss >> firstName >> lastName >> cPhone >> email >> birthday;
        getline(ss, note);

        if ((firstName + " " + lastName) == fullName) {
            found = true;
            cout << "Editing contact:\n";
            cout << "Enter new First Name: ";
            cin >> firstName;
            cout << "Enter new Last Name: ";
            cin >> lastName;
            cout << "Enter new Phone: ";
            cin >> cPhone;
            cout << "Enter new email: ";
            cin >> email;
            cout << "Enter new birthday: ";
            cin >> birthday;
            cout << "Enter new note: ";
            cin.ignore();
            getline(cin, note);

            outFile << firstName << " " << lastName << " " << cPhone << " " << email << " " << birthday << " " << note << endl;
        } else {
            outFile << contact << endl;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    } else {
        cout << "Contact updated successfully.\n";
    }

    outFile.close();
}
