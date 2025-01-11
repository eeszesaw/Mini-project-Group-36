#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "ViewContact.hpp"

using namespace std; 

void loadContacts(const string& filename, vector<Contact>& contacts) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, phone, email, birthday, note;
        
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, birthday, ',');
        getline(ss, note);

        contacts.push_back(Contact(name, phone, email, birthday, note));
    }
    file.close();
}

int main() {
    vector<Contact> contacts;
    string filename = "contacts.txt";

    loadContacts(filename, contacts);

    if (contacts.empty()) {
        cout << "No contacts found." << endl;
        return 0;
    }

    cout << "Contacts List:" << endl;
    for (const auto& contact : contacts) {
        contact.display();
    }

    return 0;
}

Contact::Contact() : name(""), phone_number(""), email(""), birthday(""), note("") {}

Contact::Contact(const string& name, const string& phone, const string& email, const string& birthday, const string& note)
    : name(name), phone_number(phone), email(email), birthday(birthday), note(note) {}

void Contact::display() const {
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone_number << endl;
    cout << "Email: " << email << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Note: " << note << endl;
    cout << "----------------------------" << endl;
}