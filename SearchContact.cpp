#include <algorithm> // For transform function
#include <cctype>    // For tolower function
void searchContact() {
    string query;
    cout << "\nEnter a single letter (case-insensitive) to search for:";
    getline(cin, query);
    // Check if input is a single letter
    if (query.length() != 1 || !isalpha(query[0])) {
        cout << "Please enter a valid single alphabet letter.\n";
        return;
    }
    char queryChar = tolower(query[0]);
    vector<Contact> contacts = loadContacts();
    bool found = false;
    for (const auto& contact : contacts) {
        // Check if the character exists in any part of the contact fields (case-insensitive)
        if (containsChar(contact.firstName, queryChar) ||
            containsChar(contact.lastName, queryChar) ||
            containsChar(contact.phoneNumber, queryChar)) {
            
            cout << "\nContact Found:\n";
            cout << "Name: " << contact.firstName << " " << contact.lastName << "\n";
            cout << "Phone: " << contact.phoneNumber << "\n";
            cout << "Email: " << contact.email << "\n";
            cout << "Birthday: " << contact.birthday << "\n";
            cout << "Note: " << contact.note << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No contact found matching the query.\n";
    }
}
