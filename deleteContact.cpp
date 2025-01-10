#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Assuming Contact is already defined globally or in a common header
extern vector<Contact> contacts;

void deleteContact() {
    string name;
    cout << "Enter the name of the contact to delete: ";
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
