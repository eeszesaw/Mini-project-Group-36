#include "EditContact.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void editContact() {
    string phone;
    cout << "Enter phone number of the contact you want to edit: ";
    cin >> phone;

    ifstream inFile("contacts.txt");
    vector<string> contacts;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        contacts.push_back(line);
    }
    inFile.close();

    ofstream outFile("contacts.txt");
    for (auto& contact : contacts) {
        stringstream ss(contact);
        string firstName, lastName, cPhone, email, birthday, note;
        ss >> firstName >> lastName >> cPhone >> email >> birthday;
        getline(ss, note);

        if (cPhone == phone) {
            found = true;
            cout << "Editing contact:\n";
            cout << "Enter new name: ";
            cin >> firstName >> lastName;
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
