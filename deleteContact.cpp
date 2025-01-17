#include "DeleteContact.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void deleteContact() {
    string fullName;
    cout << "Enter the full name of the contact to delete: ";
    cin.ignore();
    getline(cin, fullName);

    ifstream inFile("contacts.txt");
    vector<string> contacts;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        contacts.push_back(line);
    }
    inFile.close();

    ofstream outFile("contacts.txt");
    for (const auto& contact : contacts) {
        stringstream ss(contact);
        string firstName, lastName, cPhone, email, birthday, note;
        ss >> firstName >> lastName >> cPhone >> email >> birthday;
        getline(ss, note);

        if ((firstName + " " + lastName) != fullName) {
            outFile << contact << endl;
        } else {
            found = true;
            cout << "Contact deleted successfully.\n";
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }

    outFile.close();
}
