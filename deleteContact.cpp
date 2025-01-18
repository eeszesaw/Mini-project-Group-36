#include "DeleteContact.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

void deleteContact() {
    string fullName;
    cout << "Enter the full name of the contact to delete: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, fullName);

    fullName = trim(toLower(fullName));

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

    for (const auto& contact : contacts) {
        stringstream ss(contact);
        string firstName, lastName, phone, email, birthday, note;
        ss >> firstName >> lastName >> phone >> email >> birthday;
        getline(ss, note);

        string fullNameFromFile = toLower(trim(firstName + " " + lastName));

        // Match query with full name or phone
        if (fullName != fullNameFromFile) {
            outFile << contact << endl;
        } else {
            found = true;
            cout << "Contact deleted successfully.\n";
        }
    }

    if (!found) {
        cout << "No contact found with the full name '" << fullName << "'.\n";
    }

    outFile.close();
}

