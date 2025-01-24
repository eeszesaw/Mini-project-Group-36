
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "AddContact.hpp"
#include "Contact.hpp"  // Include the Contact class
#include "ContactManager.hpp"

using namespace std;

// Function to check if the day is valid for the given month and year (including leap year for February)
bool isValidDay(int month, int day, int year) {
    // Days in months for a non-leap year
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check if the month is valid
    if (month < 1 || month > 12) {
        cout << "Oops! The month should be between 1 and 12. Please try again.\n";
        return false;
    }

    // Special check for February (month 2) in leap years
    if (month == 2) {
        // Check for leap year
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        int daysInFebruary = isLeap ? 29 : 28;
        
        if (day < 1 || day > daysInFebruary) {
            cout << "Oops! February only has " << daysInFebruary << " days. Please enter a valid day.\n";
            return false;
        }
    } else {
        // For other months, validate the day range
        if (day < 1 || day > daysInMonth[month - 1]) {
            cout << "Hmm, that day doesn't seem to exist for this month. Please enter a valid day.\n";
            return false;
        }
    }

    return true;
}

// Function to validate birthday format
bool isValidBirthday(const string& birthday) {
    if (birthday.length() != 10 || birthday[4] != '-' || birthday[7] != '-') {
        cout << "Oops! Please use the YYYY-MM-DD format, like 1990-01-01.\n";
        return false;
    }

    // Extract year, month, and day from the string
    int year, month, day;
    char dash;
    stringstream ss(birthday);

    ss >> year >> dash >> month >> dash >> day;

    // Validate the day for the given month and year
    return isValidDay(month, day, year);
}

// Function to validate phone number
bool isValidPhone(const string& phone) {
    if (phone.length() < 10 || phone.length() > 15) {
        cout << "Oops! It looks like the phone number should be between 10 and 15 digits. Can you check and try again?\n";
        return false;
    }
    for (char ch : phone) {
        if (!isdigit(ch)) {
            cout << "Hmm, seems like there was an error. Phone numbers should only have digits. Could you double-check?\n";
            return false;
        }
    }
    return true;
}
    
// Updated function to validate email
bool isValidEmail(const string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);  // Ensure dot is after '@'

    // Check if '@' exists, '.' exists after '@', and the domain has at least one character after '.'
    if (atPos == string::npos || dotPos == string::npos || dotPos <= atPos + 1 || dotPos == email.length() - 1) {
        cout << "Hmm, that email doesn't seem quite right. Can you enter a valid one, please?\n";
        return false;
    }
    return true;
}

// Function to add a new contact
void addContact(ContactManager& manager) {
    string firstName, lastName, phone, email, birthday, note;

    cout << "Hey there! Let's get started with adding a new contact.\n";
    cout << "Please provide the First Name: ";
    cin >> firstName;

    cout << "And now, the Last Name: ";
    cin >> lastName;

    do {
        cout << "Great! Now, please provide a valid Phone Number (10-15 digits): ";
        cin >> phone;

        // Clear input buffer if invalid input is entered
        if (cin.fail()) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
        }
    } while (!isValidPhone(phone));

    do {
        cout << "Thanks! Now, please enter a valid Email address: ";
        cin >> email;
    } while (!isValidEmail(email));

    do {
        cout << "Almost done! Now, please enter the Birthday (YYYY-MM-DD): ";
        cin >> birthday;
    } while (!isValidBirthday(birthday));

    cout << "Lastly, you can add a Note for this contact (Optional): ";
    cin.ignore();  // To clear any remaining newline character in the input buffer
    getline(cin, note);

    // Create a Contact object
    Contact newContact(firstName, lastName, phone, email, birthday, note);

    // Add the new contact to the manager
    manager.addContact(newContact);

    // Save all contacts to the file
    manager.saveAllContacts();

    cout << "Yay! The contact has been successfully added. You're doing great!\n";
}
