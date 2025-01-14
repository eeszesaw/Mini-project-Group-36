#include "AddContact.hpp"
#include <iostream>
#include <limits>
#include "ContactManager.hpp" 

using namespace std;

// Function to validate phone number
bool isValidPhone(const string& phone) {
    if (phone.length() < 10 || phone.length() > 15) {
        cout << "Phone number must be between 10 and 15 digits.\n";
        return false;
    }
    for (char ch : phone) {
        if (!isdigit(ch)) {
            cout << "Phone number must only contain digits.\n";
            return false;
        }
    }
    return true;
}

// Function to validate email
bool isValidEmail(const string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    if (atPos == string::npos || dotPos == string::npos) {
        cout << "Invalid email format.\n";
        return false;
    }
    return true;
}

// Function to validate birthday format
bool isValidBirthday(const string& birthday) {
    if (birthday.length() != 10 || birthday[4] != '-' || birthday[7] != '-') {
        cout << "Birthday must be in the format YYYY-MM-DD.\n";
        return false;
    }
    for (char ch : birthday) {
        if (ch != '-' && !isdigit(ch)) {
            cout << "Birthday must contain only digits and dashes.\n";
            return false;
        }
    }
    return true;
}

// Function to add a contact
void addContact() {
    string firstName, lastName, phone, email, birthday, note;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    do {
        cout << "Enter Phone Number (10-15 digits): ";
        cin >> phone;
    } while (!isValidPhone(phone));

    do {
        cout << "Enter Email: ";
        cin >> email;
    } while (!isValidEmail(email));

    do {
        cout << "Enter Birthday (YYYY-MM-DD): ";
        cin >> birthday;
    } while (!isValidBirthday(birthday));

    cout << "Enter Note (Optional): ";
    cin.ignore();
    getline(cin, note);

    // Create a Contact object
    Contact newContact(firstName, lastName, phone, email, birthday, note);

    // Create ContactManager object and pass the contact
    ContactManager manager;
    manager.addContact(newContact);  // Call addContact with a valid Contact object

    cout << "Contact added successfully!\n";
}



  
