#include "EditContact.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to trim whitespace
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Helper function to convert string to lowercase
string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void editContact() {
    string fullName;
    cout << "Enter full name of the contact you want to edit: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, fullName);  // Capture the full name
    fullName = toLower(trim(fullName));  // Normalize the input

    ifstream inFile("contacts.txt");
    if (!inFile) {
        cout << "Error opening file.\n";
        return;
    }

    vector<string> contacts;
    string line;
    bool found = false;

    // Read all lines from the file
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
        string firstName, lastName, phone, email, birthday, note;
        ss >> firstName >> lastName >> phone >> email >> birthday;
        getline(ss, note);  // Note may contain spaces

        string fullNameFromFile = toLower(trim(firstName + " " + lastName));

        if (fullNameFromFile == fullName) {
            found = true;
            cout << "Editing contact:\n";
            cout << "Enter new First Name: ";
            cin >> firstName;
            cout << "Enter new Last Name: ";
            cin >> lastName;
            cout << "Enter new Phone: ";
            cin >> phone;
            cout << "Enter new Email: ";
            cin >> email;
            cout << "Enter new Birthday: ";
            cin >> birthday;
            cout << "Enter new Note: ";
            cin.ignore();
            getline(cin, note);

            outFile << firstName << " " << lastName << " " << phone << " " << email << " " << birthday << " " << note << endl;
        } else {
            outFile << contact << endl;  // Write the unchanged contact
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    } else {
        cout << "Contact updated successfully.\n";
    }

    outFile.close();
}