#include "DeleteContact.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void deleteContact() {
    string phone;
    cout << "Enter the phone number of the contact to delete: ";
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

        if (cPhone != phone) {
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
