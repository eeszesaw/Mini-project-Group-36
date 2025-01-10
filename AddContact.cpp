#include <iostream>
#include <string>
#include <vector>
#include "AddContact.hpp"  

using namespace std;


struct Contact {
    string firstName;
    string lastName;
    string phone;
    string email;
    string birthday;
    string note;
};



bool isValidPhone(const string& phone) {
    if (phone.length() < 10 || phone.length() > 15) return false;
    for (char c : phone) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool isValidEmail(const string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos + 1);
    if (atPos == string::npos || dotPos == string::npos) return false;
    if (atPos == 0 || dotPos == atPos + 1) return false;
    if (dotPos == email.length() - 1) return false;
    return true;
}

bool isValidDate(const string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);

    for (char c : year + month + day) {
        if (!isdigit(c)) return false;
    }

    int monthNum = stoi(month);
    int dayNum = stoi(day);

    if (monthNum < 1 || monthNum > 12 || dayNum < 1 || dayNum > 31) return false;

    return true;
}

void getInput(string& input, const string& prompt) {
    cout << prompt;
    getline(cin, input);
}

void displayContact(const Contact& contact) {
    cout << "\nContact Details:\n";
    cout << "First Name: " << contact.firstName << "\n"
         << "Last Name: " << contact.lastName << "\n"
         << "Phone: " << contact.phone << "\n"
         << "Email: " << contact.email << "\n"
         << "Birthday: " << contact.birthday << "\n"
         << "Note: " << contact.note << "\n";
}

bool validateInput(const string& input, bool(*validationFn)(const string&), const string& errorMessage) {
    if (!validationFn(input)) {
        cout << errorMessage << endl;
        return false;
    }
    return true;
}

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    string input;

    
    getInput(newContact.firstName, "Enter First Name: ");
    getInput(newContact.lastName, "Enter Last Name: ");

    
    do {
        getInput(input, "Enter Phone Number (10-15 digits): ");
    } while (!validateInput(input, isValidPhone, "Invalid phone number. Please try again."));
    newContact.phone = input;

    
    do {
        getInput(input, "Enter Email: ");
    } while (!validateInput(input, isValidEmail, "Invalid email address. Please try again."));
    newContact.email = input;

    
    do {
        getInput(input, "Enter Birthday (YYYY-MM-DD): ");
    } while (!validateInput(input, isValidDate, "Invalid date format. Please try again."));
    newContact.birthday = input;

    
    getInput(newContact.note, "Enter Note: ");

    
    contacts.push_back(newContact);
    cout << "\nContact added successfully!\n";

    
    displayContact(newContact);
}

int main() {
    vector<Contact> contacts; // List to store all contacts

    cout << "=== Add New Contact ===\n";
    addContact(contacts); // Call the addContact function

    return 0;
}

