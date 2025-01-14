#include "ViewContact.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void viewContact() {
    ifstream inFile("contacts.txt");
    string line;

    cout << "\n--- Contact List ---\n";
    while (getline(inFile, line)) {
        stringstream ss(line);
        string firstName, lastName, phone, email, birthday, note;
        ss >> firstName >> lastName >> phone >> email >> birthday;
        getline(ss, note);

        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Birthday: " << birthday << endl;
        cout << "Note: " << note << endl;
        cout << "-------------------------\n";
    }
    inFile.close();
}
