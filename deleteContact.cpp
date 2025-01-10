#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

extern vector<Contact> contacts;

void deleteContact() {
    string name;
    cout << "Enter the full name of the contact to delete: ";  // Prompt for first and last name
    getline(cin, name);

    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&name](const Contact& c) { return c.name == name; });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully!\n";
    } else {
        cout << "Contact not found.\n";
    }
}

