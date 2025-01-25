/* Author : Nur Iffa Nadhirah Binti Zainal 
matric no.: 23304079
Purpose of the viewContact function:
The viewContact function reads and displays all contacts from the "contacts.txt" file. 
It extracts and prints each contact's first name, last name, phone number, email, birthday, and notes in a clear format. 
This function helps users easily view their contact information.
*/

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
        cout << endl;
    }
    inFile.close();
}
